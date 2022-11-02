//{{{
#include<bits/stdc++.h>
#define sc second
#define fr first
#define mk make_pair
#define pb push_back
#define pi pair<int,int>
using namespace std;
typedef long double ld;const ld eps=1e-10;
typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,m,tp,v[50005],T[100005];ld p,q,a[50005],b[50005];pair<ld,int>st[100005];
inline void add(int x) {for(;x<=tp;x+=x&(-x)) T[x]++;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r+=T[x];return r;}
inline void Sort(ld r)
{
	tp=0;for(int i=1;i<=n;i++)
	{
		ld A=a[i],B=b[i],ds=4*A*A*B*B-4*(A*A+1)*(B*B-r*r);if(ds<=eps) continue;
		v[i]=0,ds=sqrt(ds);ld x1=(-2*A*B-ds)/2/(A*A+1),x2=(-2*A*B+ds)/2/(A*A+1);
		ld y1=A*x1+B,y2=A*x2+B;st[++tp]=mk(atan2(y1,x1),i),st[++tp]=mk(atan2(y2,x2),i);
	}
	sort(st+1,st+tp+1);for(int i=tp;i;i--) if(!v[st[i].sc]) v[st[i].sc]=i;
}
inline char chk(ld r)
{
	Sort(r);for(int i=1;i<=tp;i++) T[i]=0;
	ll res=0;for(int i=1;i<=tp;i++) if(v[st[i].sc]^i) res+=qry(v[st[i].sc])-qry(i-1),add(v[st[i].sc]);
	return res>=m;
}
inline ld getd(int i,int j) {ld x=(b[j]-b[i])/(a[i]-a[j]),y=a[i]*x+b[i];return sqrt(x*x+y*y);}
inline ld caldis(ld r)
{
	Sort(r);set<pair<int,int> >s;ld res=0;int tot=0;
	for(int i=1;i<=tp;i++) if(v[st[i].sc]^i)
	{
		set<pair<int,int> >::iterator it=s.upper_bound(mk(i+1,0));
		while(it!=s.end()&&it->fr<v[st[i].sc]) res+=getd(st[i].sc,it->sc),it++,tot++;
		s.insert(mk(v[st[i].sc],st[i].sc));
	}
	return res+(m-tot)*r;
}
int main()
{
	int x,y;read(n),read(x),read(y),read(m),p=x/1e3,q=y/1e3;
	for(int i=1;i<=n;i++) read(x),read(y),a[i]=x/1e3,b[i]=y/1e3+a[i]*p-q;
	ld l=0,r=1e10;for(int i=0;i<100;i++) {ld md=(l+r)/2;if(chk(md)) r=md;else l=md;}
	return printf("%.10Lf\n",max(0.0L,caldis(r))),0;
}