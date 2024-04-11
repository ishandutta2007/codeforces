#include<cstdio>
const int MAXN=2e5+5;
int n;
char s[MAXN],t[MAXN];
int cnta1,cnta2;
int totb,totc,b[MAXN],c[MAXN];
int main(){
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='a') cnta1++;
		if(t[i]=='a') cnta2++;
		if(s[i]=='a'&&t[i]=='b') b[++totb]=i;
		if(s[i]=='b'&&t[i]=='a') c[++totc]=i;
	}
	if((cnta1&1)!=(cnta2&1)){
		puts("-1");
		return 0;
	}
	printf("%d\n",(totb+totc>>1)+(totb&1));
	for(int i=1;i<totb;i+=2)
		printf("%d %d\n",b[i],b[i+1]);
	for(int i=1;i<totc;i+=2)
		printf("%d %d\n",c[i],c[i+1]);
	if(totb&1){
		printf("%d %d\n",b[totb],b[totb]);
		printf("%d %d\n",b[totb],c[totc]);
	}
	return 0;
}