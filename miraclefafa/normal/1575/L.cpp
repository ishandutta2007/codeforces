#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n,a[SZ];
#define SS 37000000
int rt[SZ],an;
int mx[SS],ch[SS][2];
inline int qmax(int x,int l,int r,int ql,int qr) {
	if(!x||r<ql||qr<l) return 0;
	if(ql<=l&&r<=qr) return mx[x];
	int m=(l+r)>>1;
	return max(qmax(ch[x][0],l,m,ql,qr),
	qmax(ch[x][1],m+1,r,ql,qr));
}
inline void edt(int&x,int l,int r,int p,int q) {
	if(!x) x=++an;
	mx[x]=max(mx[x],q);
	if(l==r) return;
	int m=(l+r)>>1;
	if(p<=m) edt(ch[x][0],l,m,p,q);
	else edt(ch[x][1],m+1,r,p,q);
}
int gmax(int x,int y) {
	int m=0;
	for(;x>=1;x-=x&-x) m=max(m,qmax(rt[x],1,n,1,y));
	return m;
}
void upd(int x,int y,int z) {
	for(;x<=n;x+=x&-x) edt(rt[x],1,n,y,z);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	int ans=0;
	for(int i=1;i<=n;++i) if(a[i]>=1&&a[i]<=i){
		int dt=i-a[i]+1;
		int aa=gmax(a[i]-1,dt)+1;
		ans=max(ans,aa);
		upd(a[i],dt,aa);
	}
	cout<<ans<<"\n";
}