#include<bits/stdc++.h>
#define int long long
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define po pop_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define for0 for(int i=1;i<=n;i++) cin>>a[i];
#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
const int maxn = 1e4+10;
using namespace std;
struct s{
	int x; int y;
}a[maxn];
int b[maxn],c[maxn];
void solve()
{
	int n;  cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		b[i] = a[i].x;
		c[i] = a[i].y;
	}
	sort(b+1,b+n+1);	sort(c+1,c+n+1);
	if(n%2==0)
	{
		int t1 = b[n/2]; int t2 = b[n/2+1];
		int t3 = c[n/2]; int t4 = c[n/2+1];
		if(t1==t2 && t3==t4) cout<<1<<'\n'; 
		else if(t1==t2&&t3!=t4) cout<<t4-t3+1<<'\n'; 
		else if(t1!=t2&&t3==t4)	cout<<t2-t1+1<<'\n'; 
		else cout<<(t4-t3+1)*(t2-t1+1)<<'\n';
	}else{
		cout<<1<<'\n';
	}
	return;
}
signed main()
{
	ios;
	int tt; cin>>tt;
	while(tt--)
	{
		solve();
	}
}