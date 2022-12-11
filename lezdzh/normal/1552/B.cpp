#include<cstdio>

using namespace std;

int a[50001][6];
bool cmp(int i,int j){
	int ok=0;
	for(int k=1;k<=5;k++)
		ok+=(a[i][k]<a[j][k]);
	return ok>=3;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=5;j++)
				scanf("%d",&a[i][j]);
		int ans=1,ok=1;
		for(int i=2;i<=n;i++)
			if(!cmp(ans,i))ans=i;
		for(int i=1;i<=n;i++)
			if(i!=ans&&!cmp(ans,i))ok=0;
		printf("%d\n",ok?ans:-1);
	}
}