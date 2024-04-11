#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; return 0; }
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const ll P = 31;
const int MOD = 1e9+7;
const int inf = 1e9+9;
const ll mod = 1e9+696969;

int n,m,k,a,b,c;
ll N,M,K,A,B,C;

int main()
{
    int v;
    cin >> k >> a >> b >> v;
    
    for (int i=0; i<=10000; ++i) 
      {
          //int cnt = i +min((k-1) * i, b);
          int cnt = i + min((k-1)*i, b);
          if (cnt * v >= a) OUT(i);
      }

}