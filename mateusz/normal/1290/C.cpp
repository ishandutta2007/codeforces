#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.st <<","<<P.nd <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 300005;

int n, k, size, x, ans;
char state[N];
vector<int> whereIs[N];

int rep[N], color[N];
bool isSet[N];
int setColor[N];
int zeros[N], ones[N];
vector<int> members[N];

int find(int w) {
    return rep[w] = (w == rep[w] ? w : find(rep[w]));
}

void Union(int w, int u, int s) {
    s = 1 - s;
    int a = find(w);
    int b = find(u);
    if (a == b) return;
    
    if ((color[w] ^ color[u]) != s) {
        if (members[a].size() > members[b].size()) {
            swap(a, b);
        }
        for (auto x : members[a]) {
            color[x] = 1 - color[x];
        }
        swap(zeros[a], ones[a]);
        if (isSet[a]) {
            setColor[a] = 1 - setColor[a];
        }
    }
      
    ans -= isSet[a] ? (setColor[a] ? ones[a] : zeros[a]) : min(ones[a], zeros[a]);
    ans -= isSet[b] ? (setColor[b] ? ones[b] : zeros[b]) : min(ones[b], zeros[b]);
    
    if (members[a].size() > members[b].size()) {
        swap(a, b);
    }
    if (isSet[a]) {
        isSet[b] = true;
        setColor[b] = setColor[a];
    }
  
    for (auto x : members[a]) {
        members[b].push_back(x);
    }
    members[a].clear();
    zeros[b] += zeros[a];
    ones[b] += ones[a];
    rep[a] = b;
    
    ans += isSet[b] ? (setColor[b] ? ones[b] : zeros[b]) : min(ones[b], zeros[b]);
}

void setState(int w, int s) {
    int a = find(w);
    
    ans -= isSet[a] ? (setColor[a] ? ones[a] : zeros[a]) : min(ones[a], zeros[a]);
    isSet[a] = true;
    setColor[a] = (1 - s) ? color[w] : 1 - color[w];
    ans += isSet[a] ? (setColor[a] ? ones[a] : zeros[a]) : min(ones[a], zeros[a]);
}

int main() {
    
    scanf("%d %d", &n, &k);
    
    scanf("%s", &state[1]);
    for (int i = 1; i <= n; i++) {
        state[i] -= '0';
    }
    
    for (int i = 1; i <= k; i++) {
        color[i] = 0;
        rep[i] = i;
        zeros[i] = 1;
        isSet[i] = false;
        setColor[i] = 0;
        members[i].push_back(i);
    }
    
    for (int i = 1; i <= k; i++) {
        scanf("%d", &size);
        for (int j = 0; j < size; j++) {
            scanf("%d", &x);
            whereIs[x].push_back(i);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (whereIs[i].size() == 1) {
            setState(whereIs[i][0], state[i]);
        } else if (whereIs[i].size() > 1) {
            Union(whereIs[i][0], whereIs[i][1], state[i]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}