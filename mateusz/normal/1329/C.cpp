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
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = (1 << 21) + 5;

int a[N];
int h, g, n;
long long ans;

bool canRemove(int pos) {
    int left = 2 * pos;
    int right = 2 * pos + 1;
    if (!a[left] && !a[right]) {
        return (pos > (1 << g) - 1);
    }
    if (a[left] > a[right]) {
        return canRemove(left);
    } else {
        return canRemove(right);
    }
}

void remove(int pos) {
    int left = 2 * pos;
    int right = 2 * pos + 1;
    if (!a[left] && !a[right]) {
        a[pos] = 0;
        return;
    }
    if (a[left] > a[right]) {
        swap(a[pos], a[left]);
        remove(left);
    } else {
        swap(a[pos], a[right]);
        remove(right);
    }
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &h, &g);
        n = (1 << h) - 1;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ans += a[i];
        }
        priority_queue<pair<int, int> > Q;
        Q.push({a[1], 1});
        debug(ans);
        vector<int> v;
        while (!Q.empty()) {
            int val = Q.top().first;
            int pos = Q.top().second;
            Q.pop();
            if (a[pos] != val) continue;
            
            if (canRemove(pos)) {
                ans -= val;
                debug("remove ", pos, a[pos], ans);
                v.push_back(pos);
                remove(pos);
                Q.push({a[pos], pos});
            } else {
                if (a[2 * pos] > 0) {
                    Q.push({a[2 * pos], 2 * pos});
                }
                if (a[2 * pos + 1] > 0) {
                    Q.push({a[2 * pos + 1], 2 * pos + 1});
                }
            }
        }
        printf("%lld\n", ans);
        for (int x : v) {
            printf("%d ", x);
        }
        printf("\n");
        for (int i = 1; i <= (1 << h) - 1; i++) {
            a[i] = 0;
        }
    }
    
    return 0;
}