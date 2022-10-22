#include <bits/stdc++.h>
#define pii pair<int,int> 
#define all(x) x.begin(),x.end()
#define ll long long 
#define mp make_pair
inline int mabs(int x) {return x<0?-x:x;}
using namespace std;
inline void chmin(int &x,int b) {x=min(x,b);}
inline void chmax(int &x,int b) {x=max(x,b);}
const int inf=1039714778;
const int mod=998244353;
const int i6=166374059;
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31) & mod;}

int n,t;
int x[2005],y[2005];

int f0(int x)
{
	return x+1;
}

int f1(int x)
{
	return 1LL*x*(x+1)/2%mod;
}

int f2(int x)
{
	return 1LL*x*(x+1)%mod*(2*x+1)%mod*i6%mod;
}

int calc(int a,int b)
{
	if(a<0 || b<0) return 0;
	int k=min(a,b)/2;
	int s=(1LL*a*b%mod*f0(k)-2LL*(a+b)*f1(k)+4LL*f2(k)-1LL*a*b%mod*(t+1))%mod;
	if(s<0) s+=mod;
	return s;
}

vector<pii> vx,vy;
int px[2005],py[2005];
int h0[2005],h1[2005];

int calc(int a,int b,int c,int d,int len)
{
	a=vx[a].second;b=vx[b].second;
	c=vy[c].second;d=vy[d].second;
	int w=calc((x[a]+t)-(x[b]-t)+1,(y[c]+t)-(y[d]-t)+1);
	if(len & 1) return mod-w;
	else return w;
}

void solve()
{
	cin>>n>>t;
	for(int i=0;i<n;i++) scanf("%d%d",x+i,y+i);
	vx.clear();
	vy.clear();
	for(int i=0;i<n;i++)
	{
		vx.emplace_back(x[i],i);
		vy.emplace_back(y[i],i);
	}
	sort(all(vx));
	sort(all(vy));
	for(int i=0;i<n;i++) px[vx[i].second]=i;
	for(int i=0;i<n;i++) py[vy[i].second]=i;

	int res=0;
	set<int> squ;
	for(int i=0;i<n;i++)
	{
		squ.clear();
		for(int j=i;j<n;j++)
		{
			auto it=squ.insert(py[vx[j].second]).first;
			auto jt=squ.find(py[vx[i].second]);
			if(*it>*jt) swap(it,jt);
			if(it==jt) chadd(res,calc(i,i,*it,*it,1));
			else
			{
				if(jt!=next(it)) continue;
				chadd(res,calc(i,j,*it,*jt,2));
				if(it!=squ.begin()) chadd(res,calc(i,j,*prev(it),*jt,3));
				if(next(jt)!=squ.end()) chadd(res,calc(i,j,*it,*next(jt),3));
				if(it!=squ.begin() && next(jt)!=squ.end()) chadd(res,calc(i,j,*prev(it),*next(jt),4));
			}
		}
	}
	cout<<res<<endl;
}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("fire.in","r",stdin);
	// freopen("fire.out","w",stdout);
	int T=1;
	// cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}