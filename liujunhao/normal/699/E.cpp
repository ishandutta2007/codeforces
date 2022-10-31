#include<cstdio>
#include<algorithm>
#define MAXN 20
using namespace std;
int n,k;
double f[1<<MAXN],sum[1<<MAXN],ans[MAXN+10];
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
double p[MAXN+10];
void read(){
	Read(n),Read(k);
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%lf",&p[i]);
		if(p[i]>1e-8)
			cnt++;
	}
	if(cnt<=k){
		for(int i=1;i<=n;i++)
			if(p[i]>1e-8)
				printf("1 ");
			else
				printf("0 ");
		exit(0);
	}
}
void dp(){
	int i,j;
	f[0]=1;
	for(i=1;i<(1<<n);i++){
		for(j=1;j<=n;j++)
			if(i&(1<<(j-1))){
				sum[i]=sum[i^(1<<(j-1))]+p[j];
				break;
			}
		for(j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				f[i]+=f[i^(1<<(j-1))]*p[j]/(1-sum[i^(1<<(j-1))]);
			}
		}
		if(__builtin_popcount(i)==k)
			for(j=1;j<=n;j++)
				if(i&(1<<(j-1)))
					ans[j]+=f[i];
	}
}
int main()
{
	read();
	dp();
	for(int i=1;i<=n;i++)
		printf("%.10lf ",ans[i]);
}