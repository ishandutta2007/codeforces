#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define for00 for(int i=1;i<=n;i++) cin>>a[i];
#define for0 for(int i=0;i<n;i++)
#define for1 for(int i=1;i<=n;i++)
#define for2(i,a,b) for(int i=a; i<=b;i++)
#define for3(i,a,b) for(int i=a; i>=b;i--)
using namespace std;

const int N = 2e5+10;
int a[N],b[N],c[N];
int n,l,r; 
int t,ll,rr;
void init()
{
	t=0; rr=0; ll=0;
}
void print(int x)
{
	cout<<x<<endl;
}
void solve()
{
	memset(a,0,sizeof a); memset(b,0,sizeof b); memset(c,0,sizeof c);
	cin>>n>>l>>r;
	for2(i,1,l) 
	{
		int x; 	cin>>x; b[x]++;
	}
	for2(i,1,r) 
	{ 
		int x; 	cin>>x;  c[x]++;
	}
	init();
	for2(i,0,n)
	{
		t = min(c[i],b[i]);
		c[i]-=t;  b[i]-=t;
		ll+=b[i]; rr+=c[i];
	}
	if(ll==rr)
	{
		print(ll);
		return;
	}
	if(ll<rr)
	{
		int p = 0;
		for2(i,0,n)  p+=c[i]/2; p+=p;
		int cun = rr-p;
		if(cun<=ll)
		{
			print((rr-ll)/2+ll);
		}else{
			print(p/2+rr-p);
			return;
		}
	}else{
		int p=0;
		for2(i,0,n)  p+=b[i]/2; p+=p;
		int cun = ll-p;
		if(cun<=rr)
		{
			print((ll-rr)/2+rr);
			return;
		}
		else
		{
			print(p/2+ll-p);
			return;
		}
	}
}
signed main()
{
	ios;
	int tt = 1;
	cin>>tt;
	while(tt--)
	{
		solve();
	}
	


}