#include<cstdio>
#include<cstring>
using namespace std;

char s[1002];
int a[1001],b[1001];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+(s[i]=='(');
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+(s[i]==')');
	int p=-1;
	for(int i=0;i<=n;i++)
		if(a[i]==b[n]-b[i]){
			p=i;
			break;
		}
	if(a[p]==0)printf("0\n");
	else{
		printf("1\n%d\n",a[p]+b[n]-b[p]);
		int ok=0;
		for(int i=1;i<=p;i++)
			if(s[i]=='(')
				printf(ok?" %d":"%d",i),ok=1;
		for(int i=p+1;i<=n;i++)
			if(s[i]==')')
				printf(" %d",i);
		printf("\n");
	}
}