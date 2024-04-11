//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
//#define int ll
#define N 40000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int lson[N],rson[N],L[N],R[N],tag[N];
int n,rt,cnt,T,q,ans;
void pushdown(int k,int l,int r)
{
	if (!lson[k])
	{
		lson[k]=++cnt;
		L[lson[k]]=l,R[lson[k]]=l+(r-l)/2;
	}
	if (!rson[k])
	{
		rson[k]=++cnt;
		L[rson[k]]=l+(r-l)/2+1,R[rson[k]]=r;
	}
	if (!tag[k]) return;
	L[lson[k]]+=tag[k];
	R[lson[k]]+=tag[k];
	tag[lson[k]]+=tag[k];
	
	L[rson[k]]+=tag[k];
	R[rson[k]]+=tag[k];
	tag[rson[k]]+=tag[k];
	tag[k]=0;
}
void pushup(int k)
{
	L[k]=L[lson[k]];
	R[k]=R[rson[k]];
}
void update(int &k,int l,int r,int T,int val,int tp)
{
//	cout<<"?"<<k<<" "<<l<<" "<<r<<" "<<<T<<" "<<val<<" "<<tp<<endl;
	if (!k)
	{
		k=++cnt;
		L[k]=l,R[k]=r;
		tag[k]=0;
	}
	if (l==r)
	{
		if (tp==0)
		{
			if (L[k]<T)
			{
				L[k]+=val;
				R[k]+=val;
				tag[k]+=val;
				return;
			} else return;
		} else
		{
			if (L[k]>T)
			{
				L[k]+=val;
				R[k]+=val;
				tag[k]+=val;
				
				return;
			} else return;
		}
	}
				
	pushdown(k,l,r);
	int mid=l+(r-l)/2;
//	cout<<"?"<<k<<" "<<l<<" "<<r<<" ".<<T<<" "<<val<<" "<<tp<<" "<<R[lson[k]]<<endl;
	if (tp==0)
	{
		if (R[k]<T)
		{
			L[k]+=val;
			R[k]+=val;
			tag[k]+=val;
			return;
		}
		if (L[rson[k]]<T)
		{
			L[lson[k]]+=val;
			R[lson[k]]+=val;
			tag[lson[k]]+=val;
			update(rson[k],mid+1,r,T,val,tp);
		}
		else update(lson[k],l,mid,T,val,tp);
	} else
	{
		if (L[k]>T)
		{
			L[k]+=val;
			R[k]+=val;
			tag[k]+=val;
			return;
		}
		if (R[lson[k]]>T)
		{
			L[rson[k]]+=val;
			R[rson[k]]+=val;
			tag[rson[k]]+=val;
			update(lson[k],l,mid,T,val,tp);
		} else
			update(rson[k],mid+1,r,T,val,tp);
	}
	pushup(k);
}	
int query(int k,int l,int r,int L1)
{
	if (!k) return 0;
	if (l==r) return L[k];
	pushdown(k,l,r);
	int mid=l+(r-l)/2;
	if (L1<=mid) return query(lson[k],l,mid,L1);
	return query(rson[k],mid+1,r,L1);
}
void LYC_music()
{
	n=read();
	rt=0;
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		T=read();
		update(rt,-10,1e9+10,T,1,0);
		update(rt,-10,1e9+10,T,-1,1);
		q=read();
		while (q--)
		{
			int x=(read()+ans)%1000000001;
			ans=query(1,-10,1e9+10,x);
			writeln(ans);
		}
	}
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/