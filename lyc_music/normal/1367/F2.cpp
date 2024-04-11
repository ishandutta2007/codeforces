//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],b[N],ans,lst;
map<int,int>Mp;
int po[N];
int m;
vector<int>G[N];
void LYC_music()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=a[i];
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b,G[a[i]].push_back(i);
	ans=n-1;
//	return;
	int lst=G[m].size();
	for (int i=m;i>1;i--)
	{
//		cout<<"?"<<i<<endl;
		ans=min(ans,n-lst);
//		if (ans==15) cout<<"?"<<i<<" "<<endl;
//		cout<<"?"<<" "<<i<<" "<<lst<<endl;
		if (G[i][0]>G[i-1][G[i-1].size()-1])
		{
//			cout<<"?"<<endl;
			lst+=G[i-1].size();
		} else
		if (G[i-1][0]>G[i][G[i].size()-1])
		{
			lst=G[i-1].size();
		} else
		{
//			cout<<"?"<<endl;
			int x=lower_bound(G[i].begin(),G[i].end(),G[i-1].back())-G[i].begin();
			ans=min(ans,n-((int)G[i].size()-x+(int)G[i-1].size()));
			int nxtlst=G[i].size()-x+(int)G[i-1].size();
			for (int j=(int)G[i-1].size()-2;j>=0;j--)
			{
				while (x&&G[i][x-1]>G[i-1][j]) x--;
				ans=min(ans,n-((int)G[i].size()-x+j+1));
				if (x==0) 
					ans=min(ans,n-(lst-x+j+1));
					
			}
			lst=nxtlst;
		}
	}
	ans=min(ans,n-lst);
	writeln(ans);	
	Mp.clear();
	for (int i=1;i<=m;i++) G[i].clear();
}
signed main()
{
	int T=read();
	while (T--)
	{
		LYC_music();
	}
}
/*

*/