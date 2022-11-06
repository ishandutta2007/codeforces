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

const int N = 1005;

int n;
int A[N], cnt[N];

void insert(int w) {
    cnt[w]++;
}

void remove(int w) {
    cnt[w]--;
}

int mex() {
    for (int i = 0; i <= n; i++) if (cnt[i] == 0) return i;
}

bool sorted() {
    for (int i = 2; i <= n; i++) {
        if (A[i] < A[i - 1]) return false;
    }
    return true;
}

int main() {
    
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) {
            cnt[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            insert(A[i]);
        }
        int mini = 1;
        vector<int> ans;
        for (int i = 1; i <= 2 * n; i++) {
            if (sorted()) break;
            int m = mex();
            if (m < mini) {
                ans.push_back(mini);
                remove(A[mini]);
                A[mini] = m;
                insert(A[mini]);
                mini++;
            } else {
                ans.push_back(m);
                remove(A[m]);
                A[m] = m;
                insert(A[m]);
            }
        }
        printf("%d\n", ans.size());
        for (int x : ans) {
            printf("%d ", x);
        }
        printf("\n");
    }
    
    return 0;
}