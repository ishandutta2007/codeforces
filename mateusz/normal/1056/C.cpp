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

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int N = 2005;

int n, m;
int power[N];
int t[N];
int from[N], to[N], edge[N];
bool isTaken[N];
int turn;

bool cmp(int a, int b) {
    return power[a] < power[b];
}

void take(int x) {
    cout << x << endl;
    isTaken[x] = true;
}

int main() {
    
    cin >> n >> m;
    n *= 2;
    for (int i = 1; i <= n; i++) {
        cin >> power[i];
        t[i] = i;
    }
    sort(t + 1, t + 1 + n, cmp);
    
    for (int i = 1; i <= m; i++) {
        cin >> from[i] >> to[i];
        edge[from[i]] = to[i];
        edge[to[i]] = from[i];
    }
    
    cin >> turn;
    turn--;
    
    int lastTaken = -1;
    int remaining = n;
    while (true) {
        int hisChoice;
        if (remaining == 0) break;
        remaining--;
        if (turn == 0) {
            if (lastTaken != -1 && edge[lastTaken] != 0 && !isTaken[edge[lastTaken]]) {
                take(edge[lastTaken]);
            } else {
                int myChoice = -1;
                for (int i = n; i >= 1; i--) {
                    if (!isTaken[t[i]] && edge[t[i]] > 0) {
                        myChoice = t[i];
                        break;
                    }
                }
                if (myChoice == -1) {
                    for (int i = n; i >= 1; i--) {
                        if (!isTaken[t[i]]) {
                            myChoice = t[i];
                            break;
                        }
                    }
                }
                take(myChoice);
            }
        } else {
            cin >> hisChoice;
            if (hisChoice == -1) {
                return 0;
            }
            isTaken[hisChoice] = true;
            lastTaken = hisChoice;
        }
        turn = 1 - turn;
    }
    
    return 0;
}