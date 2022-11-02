#include<cstdio>
const int M=1000000007;
char s[102];
int i,n;
long long p,S;
int main(){
	scanf("%s",s+1);
	while(s[n+1])n++;
	for(i=1,p=1;i<n;i++)
		p=p*2%M;
	for(i=n;i;i--){
		if(s[i]==49)
			S=(S+p)%M;
		p=p*2%M;
	}
	printf("%lld",S);
}