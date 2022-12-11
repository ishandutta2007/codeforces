#include<cstdio>

using namespace std;

int a[10001];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	a[++a[0]]=0;
	for(int i=1;i<k;i++){
		a[++a[0]]=i;
		a[++a[0]]=i;
		for(int j=1;j<i;j++){
			a[++a[0]]=j;
			a[++a[0]]=i;
		}
		a[++a[0]]=0;
	}
	for(int i=1;i<=n;i++)
		printf("%c",a[(i-1)%a[0]+1]+'a');
	printf("\n");
}