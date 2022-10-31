#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 10000
using namespace std;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
typedef long long LL;
int n,p[MAXN+10],s[MAXN+10],c;
LL f[2][MAXN+10],ans=0x7fffffffffffffffll;
void read(){
	Read(n),Read(c);
	int i;
	for(i=1;i<=n;i++)
		Read(p[i]);
	for(i=1;i<=n;i++)
		Read(s[i]);
}
void solve(){
	int i,j,now=1;
	for(i=1;i<=n;i++,now^=1)
		for(j=0;j<=i;j++)
			f[now][j]=min(j?f[now^1][j-1]+s[i]:0x7fffffffffffffffll,j<i?f[now^1][j]+p[i]+1ll*j*c:0x7fffffffffffffffll);
	for(j=0;j<=n;j++)
		ans=min(ans,f[n&1][j]);
}
int main()
{
	read();
	solve();
	printf("%I64d\n",ans);
}