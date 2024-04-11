#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
#define MAXN 100
int n,a[MAXN+10],tot;
int b[MAXN+10];

template<class T>
void Read(T &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return ;
		}
}
void read(){
	Read(n);
	for(int i=1;i<=n;i++)		Read(a[i]),tot+=a[i];

	for(int i=1;i<=n;i++)
		Read(b[i]);
}
int f[110][10010];
void solve(){
	int i,j,k;
	memset(f,0x80,sizeof f);
	f[0][0]=0;
	for(i=1;i<=n;i++)
		for(j=i;j>=0;j--)
			for(k=10000;k>=0;k--)
				f[j][k]=max(k>=a[i]?f[j][k-a[i]]:int(0x80808080),j>0?f[j-1][k]+b[i]:int(0x80808080));
	for(j=1;j<=n;j++)
		for(k=0;k<=10000;k++)
			if(f[j][k]>=tot){
				printf("%d %d\n",j,k);
				return;
			}
}
int main()
{
	read();
	solve();
	return 0;
}