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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 1005;

int A[N];
int pos[N];

int n;

int main() {
//     srand(time(0) * atoi(argv[1]));
        scanf("%d", &n);
//     n = rand() % 10 + 1;
//     cerr << n << endl;
    vector<pair<int, int> > renum;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
//             A[i] = rand() % 10 + 1;
//             cerr << A[i] << " ";
            renum.push_back({A[i], i});
        
        }
//         cerr << endl;
        sort(renum.begin(), renum.end());
        int id = 0;
        for (int i = 0; i < renum.size(); i++) {
            A[renum[i].second] = i + 1;
        }
        
        for (int i = 1; i <= n; i++) {
            pos[A[i]] = i;
        }
        
        
        
        vector<pair<int, int> > ans;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < n; j++) {
                if (pos[j] > pos[j + 1]) {
                    ans.push_back({pos[j + 1], pos[j]});
                    swap(pos[j], pos[j + 1]);
                    
                }
            }
        }
        /*
        for (int r = 1; r <= n; r++) {
            for (int i = n; i - r >= 1; i--) {
                if (pos[i] < pos[i - r]) {
                    ans.push_back({pos[i], pos[i - r]});
                    swap(pos[i], pos[i - r]);
                }
            }
        }*/
/*        
        
        cerr << endl;
        vector<pair<int, int> > inv;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (A[i] > A[j]) {
                    inv.push_back({i, j});
                }
            }
        }*/
//         sort(inv.begin(), inv.end(), [&](auto a, auto b) { if (A[a.first] - A[a.second] != A[b.first] - A[b.second]) return A[a.first] - A[a.second] < A[b.first] - A[b.second]; else return make_pair(make_pair(A[a.first], A[a.second]), a) > make_pair(make_pair(A[b.first], A[b.second]), b); });
        printf("%d\n", ans.size());
        for (auto p : ans) {
            printf("%d %d\n", p.first, p.second);
            swap(A[p.first], A[p.second]);
        }
        for (int i = 2; i <= n; i++) {
            assert(A[i] >= A[i - 1]);
        }
    
    
    return 0;
}