#include<cstdio>

using namespace std;

int a[26];
int main(){
	int k;
	scanf("%d",&k);
	if(k==0){
		printf("a");
		return 0;
	}
	for(int i=1000;i>=2;i--)
		while(i*(i-1)>>1<=k){
			k-=i*(i-1)>>1;
			a[++a[0]]=i;
		}
	for(int i=1;i<=a[0];i++)
		for(int j=1;j<=a[i];j++)
			printf("%c",i-1+'a');
}