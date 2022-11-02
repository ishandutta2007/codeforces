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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int P=1e9+7,N=1000005;int n,a[N],g[N],gt,cn[3],rs;char v[N];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int getv() {return cn[1]>cn[2]?cn[2]+(cn[1]-cn[2])/3*2:cn[2];}
inline void sub0() {printf("%d %d\n",ksm(3,n/3),rs+getv());}
inline void sub1()
{
	//for(int i=1;i<=gt;i++) printf("%d%c",g[i],i==gt?'\n':' ');
	int as=1e9;for(int i=1;i<=gt;i++) if(g[i]>4)
	{//3+...+4
		int tp=rs-(g[i]-1)/3+(g[i]-5)/3+1;
		cn[g[i]%3]--,cn[(g[i]-4)%3]++;
		as=min(as,tp+getv());
		cn[g[i]%3]++,cn[(g[i]-4)%3]--;
	}else if(g[i]==4) cn[1]--,as=min(as,rs-1+getv()),cn[1]++;
	if(cn[1]&&cn[0]) cn[1]--,cn[0]--,as=min(as,rs+1+getv()),cn[1]++,cn[0]++;//3+...+(3+1)
	if(cn[2]>1) cn[2]-=2,as=min(as,rs+getv()),cn[2]+=2;//3+...+2+2
	if(cn[2]&&cn[1]>=2) cn[2]--,cn[1]-=2,as=min(as,rs+1+getv()),cn[2]++,cn[1]+=2;//3+..+(1+1)+2
	if(cn[1]>=4) cn[1]-=4,as=min(as,rs+2+getv()),cn[1]+=4;
	printf("%lld %d\n",ksm(3,n/3-1)*4ll%P,as);
}
inline void sub2()
{
	if(cn[2]) cn[2]--;else rs++,cn[1]-=2;
	printf("%d %d\n",ksm(3,n/3)*2%P,rs+getv());
}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),v[i]=0;
	gt=rs=cn[0]=cn[1]=cn[2]=0;for(int i=1;i<=n;i++) if(!v[i])
		{int l=0,x=i;while(!v[x]) v[x]=1,x=a[x],l++;g[++gt]=l;}
	for(int i=1;i<=gt;i++) rs+=(g[i]-1)/3,cn[g[i]%3]++;
	if(n%3==0) sub0();else if(n%3==1) sub1();else sub2();
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}