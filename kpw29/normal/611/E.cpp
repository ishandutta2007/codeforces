#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const ll mod = 1e9 +7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, a , b, c, d;
int str[4];
multiset <int> s;
int t[maxn];
bool TEST = 0;
vector <int> us;
void wywal(int x)
{
    x = -x;
    if (s.empty()) return;
    multiset <int>::iterator it = s.lower_bound(x);
    if (it != s.end()) us.pb(-(*it)), s.erase(it) ;
    else TEST = 1;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=3; ++i) scanf("%d", &str[i]);
    sort(str + 1, str + 3 + 1);
    for (int i=1; i<=n; ++i) scanf("%d", &t[i]);
    sort(t + 1, t + n + 1);
    int suma = str[1] + str[2] + str[3];
    if (t[n] > suma) OUT("-1");
    s.clear();
    for (int i=1; i<=n; ++i) s.insert(-t[i]);
    int moves = 0;
    while (!s.empty())
    {
        us.clear();
        ++moves;
        int x = -(*s.begin());
        s.erase(s.begin());
        bool czy = 0;
        TEST = 0;
        for (int i=1; i<=3; ++i)
          if (x <= str[i])
          {
              if (s.size() < 2) //2 elements or less
              {
                  if (s.size() == 0) OUT(moves);
                  if ((s.size() == 1) && ((suma - str[i]) >= (-(*s.begin())) )) OUT(moves);
              }
              for (int j=1; j<=3; ++j)
                if (j != i) wywal(str[j]);
                
              if (TEST) {
                  for (int i=0; i<us.size(); ++i) s.insert(-us[i]);
                  wywal(suma - str[i]);
              }
              czy = 1;
              break;
              
          }
          
        if (!czy)
        for (int i=3; i>0; --i)
          if (x <= (suma - str[i]))
          {
              wywal(str[i]);
              break;
          }
        
    }
    cout << moves;
}