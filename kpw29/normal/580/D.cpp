#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18+3;
int tests, n, m, a, b, c, d,k;
#define maxn 1000100

ll wyn[(1 << 18) + 10][19];
ll sat[10010];
ll mat[20][20];
int main()
{
    boost;
    cin >> n >> m >> k;
    for (int i=0; i<n; ++i) cin >> sat[i];
    for (int i=1; i<=k; ++i)
    {
        cin >> a >> b >> c;
        mat[a-1][b-1] = c;
    }
    int pot = (1 << n);
    int list[20];
    for (int i=0; i<pot; ++i)
    {
        int bits[20];
        int help = i;
        int DL = 0;
        for (int j=0; j<n; ++j)
        {
            bits[j] = (help & 1);
            if (bits[j]) list[++DL] = j;
            help >>= 1;
        }
        help = i;
        ll ret = 0;
        for (int j=0; j<n; ++j)
          if (bits[j]) ret += sat[j];
        for (int help = 0; help < n; ++help) 
          if (bits[help]) wyn[i][help] = max(wyn[i][help], ret);
          else wyn[i][help] = 0; //!!!!!
        
        for (int H = 1; H <= DL; ++H)
        {
            int j = list[H];
            wyn[i][j] = max(wyn[i][j], sat[j]);
            for (int Q = 1; Q <= DL; ++Q) 
            {
              int help = list[Q];
              if (help != j) 
              {
                  wyn[i][j] = max(wyn[i][j], wyn[i ^ (1 << j)][help] + mat[help][j]);
                  wyn[i][j] = max(wyn[i][j], sat[j] + sat[help] + mat[help][j]);
                  for (int U=1; U<=DL; ++U)
                  {
                      int pom = list[U];
                    if (help != pom && pom != j)
                    wyn[i][j] = max(wyn[i][j], wyn[i ^ (1 << j) ^ (1 << help)][pom] + sat[j] + sat[help] + mat[pom][help] + mat[help][j]);
                    }
                }
            }
            
        }
    }
    
    ll WYN = 0;
    for (int i=0; i<pot; ++i)
      if (__builtin_popcount(i) == m) 
        for (int j=0; j<n; ++j) if ((i | (1 << j)) == i) WYN = max(WYN, wyn[i][j]);
    cout << WYN;
    
}