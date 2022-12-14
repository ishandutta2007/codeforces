#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int IOS = []() {ios::sync_with_stdio(0); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();
#define endl '\n'
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
const int mod = 998244353;
namespace lukas{
	int qmi(int a, int k, int p) 
	{
	    int res = 1 % p;
	    while (k)
	    {
	        if (k & 1) res = (int)res * a % p;
	        a = (int)a * a % p;
	        k >>= 1;
	    }
	    return res;
	}
	
	int C(int a, int b, int p)  // C(a, b)
	{
	    if (a < b) return 0;
	
	    int x = 1, y = 1;  // xy
	    for (int i = a, j = 1; j <= b; i --, j ++ )
	    {
	        x = (int)x * i % p;
	        y = (int) y * j % p;
	    }
	
	    return x * (int)qmi(y, p - 2, p) % p;
	}
	
	int lucas(int a, int b, int p)
	{
	    if (a < p && b < p) return C(a, b, p);
	    return (int)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
	}

}
#define lucas(a,b,p) lukas::lucas(a,b,p)
int cnt,w;
int flag[N];
void solve()
{
	memset(flag,0,sizeof flag);
	int n; cin>>n;
	w=cnt=0;
	string s; cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0') w++;
		if(!flag[i] && s[i+1]=='1' && s[i]=='1') 
		{
			cnt++;
			flag[i+1]=1;
		}
	}
	cout<<lucas(cnt+w,cnt,mod)<<endl;
} 
signed main()
{
    int tt=1;
    cin>>tt;
    while(tt--)
    {
    	solve();
	}
    return 0;
}