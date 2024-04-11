//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
vector<poly>sg;
map<vector<poly>,int>Mp;
int n,x,y,z;
int a[N];
int lenx,leny;
int ans;
int mex(int x,int y,int z)
{
	static int g[6];
	memset(g,0,sizeof(g));
	g[x]++;
	g[y]++;
	g[z]++;
	// cout<<"?"<<x<<" "<<y<<" "<<z<<" "<<g[x]<<" "<<g[y]<<" "<<g[z]<<endl;
	for (int i=0;i<5;i++) 
		if (!g[i]) return i;
	return 5;
}
poly get(int now)
{
	poly gg;
	// cout<<"gt"<<now<<endl;
	// cout<<now-x<<" "<<sg.size()<<endl;
	gg.push_back(mex(sg[max(now-x,0ll)][0],sg[max(now-y,0ll)][1],sg[max(now-z,0ll)][2]));
	// cout<<"gt"<<now<<endl;
	gg.push_back(mex(sg[max(now-x,0ll)][0],4,sg[max(now-z,0ll)][2]));
	// cout<<"gt"<<now<<endl;
	gg.push_back(mex(sg[max(now-x,0ll)][0],sg[max(now-y,0ll)][1],4));
	// cout<<"gt"<<now<<endl;
	return gg;
}
int gt(int now)
{
	if (now<=lenx) return now;
	// cout<<"??gt"<<now<<" "<<lenx<<" "<<leny<<endl;
	return ((now-lenx)%leny+lenx);
}
void BellaKira()
{
	n=read();x=read(),y=read(),z=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sg.clear();
	Mp.clear();
	vector<int>pp(3);
	sg.push_back(pp);
	// int lenx=0,leny=0;
	for (int i=1;i<=5;i++)
	{
		vector<int>now(3);
		now=get(i);
		sg.push_back(now);
	}
	for (int i=6;i;i++)
	{
		vector<int>now(3);
		now=get(i);
		vector<poly>now1(sg.end()-5,sg.end());
		if (Mp.count(now1))
		{
			lenx=Mp[now1]-1;
			leny=i-Mp[now1];
			break;
		}
		Mp[now1]=i;
		sg.push_back(now);
	}
	// cout<<lenx<<" "<<leny<<" "<<sg.size()<<endl;
	int tot=0;
	ans=0;
	for (int i=1;i<=n;i++) tot^=sg[gt(a[i])][0];
	for (int i=1;i<=n;i++)
	{
		// cout<<i<<endl;
		int now=sg[gt(a[i])][0];
		// cout<<i<<endl;
		int nowz=sg[gt(max(a[i]-x,0ll))][0];
		// cout<<i<<endl;
		int nowx=sg[gt(max(a[i]-y,0ll))][1];
		// cout<<i<<endl;
		int nowy=sg[gt(max(a[i]-z,0ll))][2];
		// cout<<i<<endl;
		ans+=(now^nowz)==tot;
		ans+=(now^nowx)==tot;
		ans+=(now^nowy)==tot;
	}
	writeln(ans);
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/