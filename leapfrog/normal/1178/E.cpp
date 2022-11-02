#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T>inline void write(T x) {{if(x<0) putchar('-'),x=-x;}{if(x>9) write(x/10);}putchar(x%10+48);}
char c[1000005],r[1000005];int rt=0,n,ls[1000005][3],nx[1000005][3];
int main()
{
	scanf("%s",c+1),n=strlen(c+1),memset(ls[1],~0x3f,sizeof(ls[1])),memset(nx[n],0x3f,sizeof(nx[n]));
	for(int i=2;i<=n+1;i++) memcpy(ls[i],ls[i-1],sizeof(ls[i])),ls[i][c[i-1]-'a']=i-1;
	for(int i=n-1;i>=0;i--) memcpy(nx[i],nx[i+1],sizeof(nx[i])),nx[i][c[i+1]-'a']=i+1;
	int i,j;for(i=0,j=n+1;i<j;)
	{
		int w,v=1e9;for(int k=0;k<3;k++) if(nx[i][k]-i+j-ls[j][k]<v) w=k,v=nx[i][k]-i+j-ls[j][k];
		if(nx[i][w]>=ls[j][w]) break;else i=nx[i][w],j=ls[j][w],r[++rt]=c[i];
	}
	if((rt<<1)+(i<j-1)<(n>>1)) return puts("IMPOSSIBLE"),0;
	for(int k=1;k<=rt;k++) putchar(r[k]);
	if(i<j-1) putchar(c[i+1]);
	for(int k=rt;k>=1;k--) putchar(r[k]);
	return putchar('\n'),0;
}