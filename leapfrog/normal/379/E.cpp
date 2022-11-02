//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
typedef long double ld;const ld eps=1e-9;
const int N=305;int n,K,a[N][N],lt;
struct ${int a,b;}l[N];ld rs[N],cf[N],pos[N];
inline ld slop($ a,$ b) {return (b.a-a.a)*1.0/(b.a-b.b-a.a+a.b);}
inline char chk($ a,$ b,$ c)
{
	if(c.a>=b.a&&c.b>=b.b) return 1;
	ld s1=slop(a,b),s2=slop(b,c);if(s2>1+eps) return 0;
	if(s2<-eps||s1>=s2-eps) return 1;else return 0;
}
int main()
{
	read(K,n);for(int i=1;i<=K;i++) for(int j=0;j<=n;j++) read(a[i][j]);
	for(int q=1;q<=n;q++)
	{
		for(int p=1;p<=K;p++)
		{
			lt=p;for(int i=1;i<=p;i++) l[i]=($){a[i][q-1],a[i][q]};
			sort(l+1,l+lt+1,[]($ a,$ b){return a.b-a.a==b.b-b.a?a.a<b.a:a.b-a.a<b.b-b.a;});
			int tl=1;for(int i=2;i<=lt;i++) if(l[i].a-l[i].b==l[i-1].a-l[i-1].b) l[tl]=l[i];else l[++tl]=l[i];
			lt=tl,tl=0;for(int i=1;i<=lt;i++)
			{
				while(tl>1&&chk(l[tl-1],l[tl],l[i])) tl--;
				while(tl>0&&l[i].a>=l[tl].a&&l[i].b>=l[tl].b) tl--;
				if(!tl||l[i].b>l[tl].b) l[++tl]=l[i];
			}pos[0]=0,pos[tl]=1;ld &rs=cf[p];rs=0;
			for(int i=1;i<tl;i++) pos[i]=(l[i].a-l[i+1].a)*1.0/(l[i+1].b-l[i].b+l[i].a-l[i+1].a);
			for(int i=1;i<=tl;i++)
			{
				ld k1=pos[i-1],k2=pos[i];
				rs+=(k2-k1)*((2-k1-k2)*l[i].a+(k1+k2)*l[i].b)/2;
			}
		}
		for(int p=1;p<=K;p++) rs[p]+=cf[p]-cf[p-1];
	}
	for(int i=1;i<=K;i++) printf("%.10Lf\n",rs[i]);
	return 0;
}