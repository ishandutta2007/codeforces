#include<cstdio>
const int N=100002,M=1000000007;
typedef long long ll;
ll ans=1;
int f[N],n,i,j,k;
char s[N];
void prework(){
	f[0]=1;
	f[1]=1;
	for(i=2;i<N;i++)
		f[i]=(f[i-1]+f[i-2])%M;
}
void work(){
	scanf("%s",s+1);
	while(s[n+1])n++;
	for(i=1;i<=n;i++)
		if(s[i]=='m'||s[i]=='w'){
			printf("0");
			return ;
		}
	for(i=1;i<=n;i++)
		if(s[i]=='n'||s[i]=='u'){
			for(j=i;s[j+1]==s[j];j++);
			ans=ans*f[j-i+1]%M;
			i=j;
		}
	printf("%lld",ans);
}
int main(){
	prework();
	work();
	//while(1);
	return 0;
}