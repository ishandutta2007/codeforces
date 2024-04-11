#include<cstdio>

using namespace std;

int a[101];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int c;
			scanf("%d",&c);
			a[c]++;
		}
	}
	int ok=0;
	for(int i=1;i<=100;i++)
		if(a[i]==n)printf(ok?" %d":"%d",i),ok=1;
	printf("\n");
}