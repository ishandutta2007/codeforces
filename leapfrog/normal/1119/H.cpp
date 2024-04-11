//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
const int P=998244353;int n,m,X,Y,Z,f1[131075],f2[131075],f3[131075],f[131075];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int pls(int x,int y) {return x+=y,x>=P?x-P:x;}
inline void fwt(int n,int *a)
{
	for(int d=1;d<n;d<<=1) for(int i=0;i<n;i+=d+d) for(int j=0;j<d;j++)
		{int x=a[i|j],y=a[i|j|d];a[i|j]=x+y,a[i|j|d]=x-y;}
}
inline void ifwt(int n,int *a)
{
	ll iv=(P+1)>>1;for(int d=1;d<n;d<<=1) for(int i=0;i<n;i+=d+d) for(int j=0;j<d;j++)
		{int x=a[i|j],y=a[i|j|d];a[i|j]=pls(x,y)*iv%P,a[i|j|d]=pls(x,P-y)*iv%P;}
}
int main()
{
	read(n),read(m),read(X),read(Y),read(Z),m=1<<m;int py=0;
	for(int i=1,a,b,c;i<=n;i++) read(a),read(b),read(c),py^=a,f1[a^b]++,f2[a^c]++,f3[b^c]++;
	int s1=pls(X,pls(Y,Z)),s2=pls(X,pls(Y,P-Z)),s3=pls(X,pls(P-Y,Z)),s4=pls(X,P-pls(Y,Z));
	fwt(m,f1),fwt(m,f2),fwt(m,f3);
	//for(int i=0;i<m;i++) printf("%d%c",f1[i],i==m-1?'\n':' ');
	//for(int i=0;i<m;i++) printf("%d%c",f2[i],i==m-1?'\n':' ');
	//for(int i=0;i<m;i++) printf("%d%c",f3[i],i==m-1?'\n':' ');
	for(int i=0,a,b,c,d;i<m;i++)
	{
		a=(n+f1[i]+f2[i]+f3[i])/4,b=(n+f1[i])/2-a,c=(n+f2[i])/2-a,d=(n+f3[i])/2-a;
		//printf("qwq %d %d %d %d\n%d %d %d %d\n",s1,s2,s3,s4,a,b,c,d);
		f[i]=1ll*ksm(s1,a)*ksm(s2,b)%P*ksm(s3,c)%P*ksm(s4,d)%P;
	}
	ifwt(m,f);for(int i=0;i<m;i++) printf("%d%c",f[i^py],i==m-1?'\n':' ');
	return 0;
}