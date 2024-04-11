#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define wait system("pause")

typedef vector<int> vi;
typedef long long int64;

const int MAXN = 2010;
const int64 MOD = 1e9 + 7;

int D, N, TM;
int64 ANS;

vi ady[MAXN];
int V[MAXN];
int T[MAXN];
bool mk[MAXN];

void set_time(int n)
{
     T[n] = TM++;
     for (int i = 0; i < (int)ady[n].size(); ++i){
         int nx = ady[n][i];
         if (T[nx] == 0)
            set_time(nx);
     }
}

bool compare(int i, int j){
     if (V[i] == V[j]) return T[i] < T[j];
     return V[i] < V[j];
}

int64 calc(int n, int p)
{
      mk[n] = true;
      int64 ans = 1;
      
      for (int i = 0; i < (int)ady[n].size(); ++i){
          int nx = ady[n][i];
          if (V[nx] <= V[p] + D && compare(p, nx) && !mk[nx]){
             ans = (ans * (calc(nx, p) + 1)) % MOD;
          }
      }      
      return (ans % MOD + MOD) % MOD;
}

int main()
{
    cin >> D >> N;
    for (int i = 0; i < N; ++i)
        cin >> V[i];
        
    for (int i = 1; i < N; ++i){
        int u, v; cin >> u >> v;
        u--; v--;
        ady[u].push_back(v);
        ady[v].push_back(u);
    }
    TM = 1;
    set_time(0);
    
    ANS = 0;
    for (int i = 0; i < N; ++i){
        memset(mk, false, sizeof mk);
        int64 cur = calc(i, i);
        //cout << cur << endl;
        ANS = (ANS + cur) % MOD;
    }
    
    cout << ANS << endl;
    //wait;
}