#include<cstdio>
const int N=100002;
int n,k,a,b,i;
char s[N];
int main(){
	scanf("%d%d%s",&n,&k,s+1);
	for(i=1;i<=n;i++)
		if(s[i]=='G'||s[i]=='T'){
			if(!a)a=i;
			else b=i;
		}
	if((b-a)%k){
		printf("NO");
		return 0;
	}
	for(i=a+k;i<b;i+=k)
		if(s[i]=='#'){
			printf("NO");
			return 0;
		}
	printf("YES");
	//	while(1);
}