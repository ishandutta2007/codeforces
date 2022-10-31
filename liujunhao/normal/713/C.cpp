#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 3000
using namespace std;
int r[MAXN+10],a[MAXN+10],n,rcnt;
long long f[MAXN+10][MAXN+10];
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF){
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
	}
}
void read(){
	Read(n);
	int i;
	for(i=1;i<=n;i++){
		Read(a[i]);
		r[i]=(a[i]-=i);
	}
	sort(r+1,r+n+1);
	rcnt=unique(r+1,r+n+1)-r-1;
}
void solve(){
	int i,j;
	long long mi;
	memset(f,0x3f,sizeof f);
	f[0][1]=0;
	for(i=1;i<=n;i++){
		mi=0x7fffffffffffffffll;
		for(j=1;j<=rcnt;j++){
			mi=min(mi,f[i-1][j]);
			f[i][j]=mi+abs(r[j]-a[i]);
		}
	}
	mi=0x7fffffffffffffffll;
	for(j=1;j<=rcnt;j++)
		mi=min(mi,f[n][j]);
	printf("%I64d\n",mi);
}
int main()
{read();
	solve();
}