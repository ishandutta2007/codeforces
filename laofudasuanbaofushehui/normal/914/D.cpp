#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>

#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;

const int N=2e6;

int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

int g[N];
#define lc (i<<1)
#define rc (lc|1)
inline void build(int i,int l,int r) {
	if (l==r) g[i]=gi();
	else {
		int mid=(l+r)>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
		g[i]=__gcd(g[lc],g[rc]);
	}
}
inline void modify(int i,int l,int r,int k) {
	if (l==r) g[i]=gi();
	else {
		int mid=(l+r)>>1;
		k<=mid?modify(lc,l,mid,k):modify(rc,mid+1,r,k);
		g[i]=__gcd(g[lc],g[rc]);
	}
}
int o;
inline void query(int i,int l,int r,int L,int R,int x) {
	if (!(g[i]%x)) return;
	if (L<=l&&r<=R) {
		if (o==2) return;
		if (l==r) o++;
		else {
			int mid=(l+r)>>1;
			query(lc,l,mid,L,R,x);
			query(rc,mid+1,r,L,R,x);
		}
	} else {
		int mid=(l+r)>>1;
		if (L<=mid) query(lc,l,mid,L,R,x);
		if (mid<R) query(rc,mid+1,r,L,R,x);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	int n=gi(),m,l,r,x;
	build(1,1,n);
	m=gi();
	while (m--)
		if (gi()==1) {
			o=0;
			l=gi(),r=gi(),x=gi();
			query(1,1,n,l,r,x);
			puts(o<2?"YES":"NO");
		} else
			x=gi(),modify(1,1,n,x);
	return 0;
}