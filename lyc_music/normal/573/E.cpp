//~~
#define setI(x) freopen(x,"r",stdin)
#define setO(x) freopen(x,"w",stdout)
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
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N];
int ans;
int f[N];
namespace KTT
{
	int K[N<<2],B[N<<2],v[N<<2],dis[N<<2],tag[N<<2],P[N<<2];
	int tr[N<<2];
    int tag1[N<<2];
	void add(int k,int y)
	{
		tag[k]+=y;
		P[k]+=y;
		dis[k]-=y;
		v[k]+=y*K[k];
	}
    void add1(int k,int y)
    {
        v[k]+=y;
        tag1[k]+=y;
    }
	void pushdown(int k)
	{
		if (!tag[k]&&!tag1[k]) return;
        if (tag[k])
        {
            add(k<<1,tag[k]);
            add(k<<1|1,tag[k]);
        }
        if (tag1[k])
        {
            add1(k<<1,tag1[k]);
            add1(k<<1|1,tag1[k]);
        }
		tag1[k]=0;tag[k]=0;
	}
	void pushup(int k)
	{
		int nowk=0,nowb=0,nowv=0;
		if (v[k<<1]>=v[k<<1|1])
		{
			K[k]=K[k<<1],B[k]=B[k<<1];
			v[k]=v[k<<1];
			nowk=K[k<<1|1],nowb=B[k<<1|1];
			nowv=v[k<<1|1];
			tr[k]=tr[k<<1];
		} else
		{
			K[k]=K[k<<1|1],B[k]=B[k<<1|1];
			v[k]=v[k<<1|1];
			nowk=K[k<<1],nowb=B[k<<1];
			nowv=v[k<<1];
			tr[k]=tr[k<<1|1];
		}
		dis[k]=min(dis[k<<1],dis[k<<1|1]);
		if (nowk>K[k])
			dis[k]=min(dis[k],(v[k]-nowv+nowk-K[k]-1)/(nowk-K[k]));
		
	}
	void update(int k,int l,int r,int L,int nowk,int nowb)
	{
		if (l==r)
		{
			K[k]=nowk;
			B[k]=nowb;
			P[k]=0;
			v[k]=nowb;
			dis[k]=inf;
			tr[k]=l;
			// cout<<"upd "<<k<<" "<<l<<" "<<r<<" "<<nowk<<" "<<nowb<<endl;
			return;
		}
		int mid=l+(r-l)/2;
		pushdown(k);
		if (L<=mid) update(k<<1,l,mid,L,nowk,nowb);
		else update(k<<1|1,mid+1,r,L,nowk,nowb);
		pushup(k);
	}
	pa query(int k,int l,int r,int L,int R)
	{
		if (L<=l&&r<=R)
		{
			return mp(v[k],tr[k]);
		}
		int mid=l+(r-l)/2;
		pushdown(k);
		if (R<=mid) return query(k<<1,l,mid,L,R);
		if (L>mid) return query(k<<1|1,mid+1,r,L,R);
		pa x=query(k<<1,l,mid,L,R),y=query(k<<1|1,mid+1,r,L,R);
		return max(x,y);
	}
	void update1(int k,int l,int r,int L,int R,int val)
	{
		if (L<=l&&r<=R)
        {
            if (dis[k]>val)
            {
				// cout<<k<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
                add(k,val);
                return;
            }
        }
		int mid=l+(r-l)/2;
		pushdown(k);
        if (L<=mid)
		    update1(k<<1,l,mid,L,R,val);
        if (R>mid)
		    update1(k<<1|1,mid+1,r,L,R,val);
		pushup(k);
	}
	void update2(int k,int l,int r,int L,int R,int val)
    {
		if (L<=l&&r<=R)
        {
			// cout<<k<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
            add1(k,val);
			return;
        }
		int mid=l+(r-l)/2;
		pushdown(k);
        if (L<=mid)
		    update2(k<<1,l,mid,L,R,val);
        if (R>mid)
		    update2(k<<1|1,mid+1,r,L,R,val);
		pushup(k);
	}
        
};
using namespace KTT;
void BellaKira()
{
    n=read();
    for (int i=1;i<=n;i++) a[i]=read(),update(1,1,n,i,a[i],a[i]);
    for (int i=1;i<=n;i++)
    {
        pa x=query(1,1,n,1,n);
		// cout<<"?"<<x.se<<" "<<x.fi<<endl;
		if (x.fi<0) break;
        ans+=x.fi;
        int u=x.se;
        if (u>1)
        {
            update2(1,1,n,1,u-1,a[u]);
        }
        if (u<n)
        {
            update1(1,1,n,u+1,n,1);
        }
        update(1,1,n,u,0,-inf);
    }
    writeln(ans);
}
signed main()
{
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}
/*

*/