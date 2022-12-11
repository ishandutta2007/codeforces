#include<cstdio>

using namespace std;

int a[1000];
int main(){
	int n,k,kk;scanf("%d%d",&n,&k);kk=k;
	for(int i=2;n!=1;i++)
		if(k==1){a[++a[0]]=n;break;}
		else if(n%i==0)a[++a[0]]=i,k--,n/=i,i--;
	if(a[0]==kk)for(int i=1;i<=a[0];i++)printf("%d ",a[i]);
	else printf("-1");
}