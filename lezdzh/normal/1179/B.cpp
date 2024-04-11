#include<cstdio>
#include<algorithm>
using namespace std;

int p[2000001],q[2000001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n+m;i++)
		for(int j=max(i-m,1);j<=min(i-1,n);j++)
			p[++p[0]]=j,q[++q[0]]=i-j;
	for(int i=1;i<=p[0]-i+1;i++){
		printf("%d %d\n",p[i],q[i]);
		if(i!=p[0]-i+1)
			printf("%d %d\n",p[p[0]-i+1],q[q[0]-i+1]);
	}
}