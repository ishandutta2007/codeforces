#include<cstdio>
using namespace std;

char s[100011];
int z[10];
int main(){
	int k,n,o=0,c=0;
	scanf("%d%s",&k,s+1);
	for(n=0;s[n+1];n++);
	for(int i=1;i<=n;i++)
		z[s[i]-'0']++,o+=s[i]-'0';
	if(o>=k){
		printf("0\n");
		return 0;
	}
	for(int i=0;i<10;i++){
		if(z[i]*(9-i)>=k-o){
			printf("%d\n",c+(k-o+9-i-1)/(9-i));
			return 0;
		}
		o+=z[i]*(9-i);
		c+=z[i];
	}
}