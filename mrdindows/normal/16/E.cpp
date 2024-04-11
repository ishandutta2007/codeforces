#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%I64d",&x)
#define ss(s)	scanf("%s",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
const int N = 19;
int n;
double p[N][N], dp[1<<N];
double go(int mask){
	// if (!(mask&(1<<win))) return 0;
	// if (mask == (1<<win))return 1;
	if (mask+1 == (1<<n))return 1;
	double &ans = dp[mask];
	if (ans >= 0) return ans;
	double res = 0;
	int i;
	int hai[20], naye[20]; 
	int hais = 0, nayes = 0;
	fo(i, n)if (mask&(1<<i)) hai[hais++] = i; else naye[nayes++] = i;
	ans = 0;
	for(int ii = 0; ii < hais; ++ii) {
	    int i = hai[ii];
	    for (int jj = 0; jj < nayes; ++jj) {
	        int j = naye[jj];
	    	res += p[i][j] * go(mask^(1<<j));
	    }
	}
	ans = res * 2.0 / hais / (hais + 1);
	return ans;
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	cin>>n;
	
	fo(j, (1<<n)) dp[j] = -10;
	fo(i, n)fo(j, n)cin>>p[i][j];

	fo(i, n) cout<<fixed<<setprecision(6)<<go(1<<i)<<" ";
	
	return 0;
}