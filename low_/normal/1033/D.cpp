#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 92233720368547757
#define mn 100005
#define FLN "test"
#define mod 998244353

int n, a[505];
map <int, int> DIVSR;

int root2(int k)
{
	int l=2, r=2000000000;
	while (r>l)
	{
		int mid=(r+l)/2;
		
		if (mid*mid<k) l=mid+1;
		else r=mid;
	}
	
	if (l*l!=k) return -1;
	else return l;
}

int root3(int k)
{
	int l=2, r=1500000;
	while (r>l)
	{
		int mid=(l+r)/2;
		
		if (mid*mid*mid<k) l=mid+1;
		else r=mid;
	}
	
	if (l*l*l!=k) return -1;
	else return l;
}

int root4(int k)
{
	int l=2, r=37607;
	while (r>l)
	{
		int mid=(r+l)/2;
		
		if (mid*mid*mid*mid<k) l=mid+1;
		else r=mid;
	}
	
	if (l*l*l*l!=k) return -1;
	else return l;
}

int MARK[505];

int GCD(int a, int b)
{
	if (b==0) return a;
	return GCD(b, a%b);
}

signed main()
{
//	freopen(FLN".inp", "r", stdin);
//	freopen(FLN".out", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i], MARK[i]=0;
	a[n+1]=-1;
	for (int i=1; i<=n; i++)
	{
		if (root4(a[i])!=-1) 
		{
			int t=root4(a[i]);
			if (DIVSR.count(t)==0) DIVSR[t]=4;
			else DIVSR[t]+=4;
			MARK[i]=5;
		}
		else if (root3(a[i])!=-1)
		{
			int t=root3(a[i]);
			if (DIVSR.count(t)==0) DIVSR[t]=3;
			else DIVSR[t]+=3;
			MARK[i]=4;
		}
		else if (root2(a[i])!=-1)
		{
			int t=root2(a[i]);
			if (DIVSR.count(t)==0) DIVSR[t]=2;
			else DIVSR[t]+=2;
			MARK[i]=3;
		}
	}
	
//	sort(a+1, a+n+1);
	for (int j=1; j<=n; j++) for (int i=1; i<n; i++) if (a[i]>a[i+1])
	{
		a[i]+=a[i+1];
		a[i+1]=a[i]-a[i+1];
		a[i]=a[i]-a[i+1];
		
		MARK[i]+=MARK[i+1];
		MARK[i+1]=MARK[i]-MARK[i+1];
		MARK[i]=MARK[i]-MARK[i+1];
	}
	
	int DUMMY=-1;
	int temp=1;
	for (int i=1; i<=n; i++) if (MARK[i]==0)
	{
		if (a[i]==a[i+1]) temp++;
		else
		{
			bool b=0;
			for (int j=1; j<=n; j++) if (a[i]!=a[j])
			{
				int g=GCD(a[i], a[j]);
				if (g==1) continue;
				
				b=1;
				if (DIVSR.count(g)==0) DIVSR[g]=temp;
				else DIVSR[g]+=temp;
				if (DIVSR.count(a[i]/g)==0) DIVSR[a[i]/g]=temp;
				else DIVSR[a[i]/g]+=temp;
				
				break;
			}
			
			if (!b)
			{
				DIVSR[DUMMY]=temp;
				DUMMY--;
				DIVSR[DUMMY]=temp;
				DUMMY--;
			}
			
			temp=1;
		}
		
		
	}
	
	int ans=1;
	for (pair <int, int> pii:DIVSR) 
	{
		ans=(ans*(pii.second+1))%mod;
	//	cerr<<pii.first<<' '<<pii.second<<'\n';
	}
	cout<<ans<<endl;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_