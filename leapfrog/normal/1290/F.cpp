#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=998244353;
int n,m,l,f[32][20][20][20][20][2][2],dx[5],dy[5];
int nx[35],ny[35],px[35],py[35],ax,bx,ay,by,A,B,res;
inline void mod(int &x) {x<0?x+=P:(x>=P?x-=P:0);}
int main()
{
	read(n),read(m),l=1<<n,l--,f[0][0][0][0][0][0][0]=1;
	for(int i=0;i<n;i++) read(dx[i]),read(dy[i]);
	for(int i=0;i<=l;i++) for(int j=0;j<n;j++) if((i>>j)&1)
		(dx[j]>0?nx:px)[i]+=abs(dx[j]),(dy[j]>0?ny:py)[i]+=abs(dy[j]);
	for(int t=0;t<31;t++) for(int i=0;i<=nx[l];i++) for(int j=0;j<=px[l];j++) for(int k=0;k<=ny[l];k++)
		for(int p=0;p<=py[l];p++) for(int a=0;a<2;a++) for(int b=0;b<2;b++) for(int s=0;s<=l;s++)
			if(!((i+nx[s]+j+px[s])&1)&&!((k+ny[s]+p+py[s])&1))
			{
				//printf("%d %d %d %d %d %d %d %d\n",t,i,j,k,p,a,b,s);
				A=a+((i+nx[s])&1)>((m>>t)&1),B=b+((k+ny[s])&1)>((m>>t)&1);
				ax=(i+nx[s])>>1,bx=(j+px[s])>>1,ay=(k+ny[s])>>1,by=(p+py[s])>>1;
				//printf("%d %d %d %d %d %d\n",A,B,ax,bx,ay,by);
				mod(f[t+1][ax][bx][ay][by][A][B]+=f[t][i][j][k][p][a][b]);
			}
	return mod(res=f[31][0][0][0][0][0][0]+P-1),printf("%d\n",res),0;
}