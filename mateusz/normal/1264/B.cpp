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

const int N = 100005;

int t[4];
vector<int> ops;

void make(int id) {
    ops.push_back(id);
    t[id]--;
}

void no() {
    printf("NO\n");
    exit(0);
}

void yes() {
    printf("YES\n");
    for (auto x : ops) {
        printf("%d ", x);
    }
    printf("\n");
    exit(0);
}

bool allZero() {
    for (int i = 0; i < 4; i++) if (t[i] != 0) return false;
    return true;
}
int main() {
    
    scanf("%d %d %d %d", &t[0], &t[1], &t[2], &t[3]);
    
    if (t[0] > t[1]) {
        while (t[0] > 1) {
            make(0);
            make(1);
        }
        make(0);
        if (!allZero()) {
            no();
        }
        yes();
    }
    if (t[2] < t[3]) {
        while (t[3] > 1) {
            make(3);
            make(2);
        }
        make(3);
        if (!allZero()) {
            no();
        }
        yes();
    }
    
    if (t[0] == t[1]) {
        while (t[0] > 0) {
            make(0);
            make(1);
        }
        if (allZero()) yes();
        make(2);
        if (allZero()) yes();
        while (t[3] > 0) {
            make(3);
            if (allZero()) yes();
            make(2);
        }
        if (allZero()) yes();
        no();
    }
    if (t[3] == t[2]) {
        while (t[3] > 0) {
            make(3);
            make(2);
        }
        if (allZero()) yes();
        make(1);
        if (allZero()) yes();
        while (t[0] > 0) {
            make(0);
            if (allZero()) yes();
            make(1);
        }
        if (allZero()) yes();
        no();
    }
    
    if (t[1] - t[0] <= t[2] - t[3]) {
         while (t[0] > 0) {
            make(0);
            make(1);
        }
        if (allZero()) yes();
        make(2);
        if (allZero()) yes();
        while (t[3] > 0) {
            make(3);
            if (allZero()) yes();
            make(2);
        }
        if (allZero()) yes();
        while (t[1] > 0) {
            make(1);
            if (t[2] == 0) break;
            make(2);
        }
        
        if (!allZero()) {
            no();
        }
        yes();
    } else {
        while (t[3] > 0) {
            make(3);
            make(2);
        }
        if (allZero()) yes();
        make(1);
        if (allZero()) yes();
        while (t[0] > 0) {
            make(0);
            if (allZero()) yes();
            make(1);
        }
        if (allZero()) yes();
        while (t[2] > 0) {
            make(2);
            if (t[1] == 0) break;
            make(1);
        }
        
        if (!allZero()) {
            no();
        }
        yes();
    }
    
    return 0;
}