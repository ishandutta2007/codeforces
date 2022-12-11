#include<cstdio>

using namespace std;

int p[501],a[501][501];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		p[x]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			a[i+p[j]-1][p[j]]=j;
			if(p[j]>p[i])--p[j];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			printf("%d%c",a[i][j],j==i?'\n':' ');
}