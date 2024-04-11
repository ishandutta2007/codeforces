#include <x86intrin.h>
#include <bits/stdc++.h>   
 
using namespace std;
     
#define F first
#define S second
#define lb lower_bound               
#define ub upper_bound
#define pb push_back
#define pf push_front    
#define ppb pop_back
#define mp make_pair
#define bpp __builtin_popcountll                                                                                        
#define sqr(x) ((x) * (x)) 
#define al 0x3F3F3F3F
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define in insert
#define ppf pop_front
#define endl '\n'
#define int long long
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
const int mod = (int)1e9 + 7;
const int N = (int)1e6 + 123;
const ll inf = (ll)3e18 + 1;
 
const double pi = acos (-1.0);
const double eps = 1e-7;                  
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
 
int n, m, res[N], ans = inf;
pii a[N], b[N];
   
inline int f (int x) {
   int kol = 0;
   for (int i = x; i < x + n; i ++) kol += abs (a[i].F - b[i - x + 1].F);      
   if (ans > kol) {
      ans = kol;
      for (int i = x; i < x + n; i ++) res[a[i].S] = b[i - x + 1].S;
   }
   return kol;
}
 
inline void boost () {                    
   ios_base :: sync_with_stdio (NULL);
   cin.tie (NULL), cout.tie (NULL);          
}                                                     
 
inline void Solve () {
   cin >> m >> n;
   for (int i = 1; i <= n; i ++) cin >> a[i].F, a[i].S = i;
   for (int i = 1; i <= n; i ++) cin >> b[i].F, b[i].S = i;
   sort (a + 1, a + n + 1);
   sort (b + 1, b + n + 1);
   for (int i = 1; i <= n; i ++) {
      a[i + n] = a[i];
      a[i].F -= m; 
   }  
   for (int i = n + 1; i <= n + n; i ++) a[i + n] = a[i], a[i + n].F += m; 
   int l = 1, r = 2 * n + 1;
   while (r - l > 1) {
      int mid = l + r >> 1;
      int v1 = f (mid), v2 = f (mid + 1);
      if (v1 <= v2) r = mid;
      else l = mid;
   }
   for (int i = l; i <= r; i ++) f (i);
   cout << ans << endl;
   for (int i = 1; i <= n; i ++) cout << res[i] << ' ';
}                                     
 
main () {                                       
// freopen (".in", "r", stdin);    
// freopen (".out", "w", stdout);              
   boost ();                                       
   int tt = 1;
// cin >> tt;   
   while (tt --) {
      Solve ();
   }                                               
   return 0;      
}