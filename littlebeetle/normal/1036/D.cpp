#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300020;
int n,m,a[N],b[N],i,j,k,l,r,s;
long long u,v;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),u+=a[i];
	scanf("%d",&m);
	for(i=1;i<=m;i++)
		scanf("%d",b+i),v+=b[i];
	i=1;j=1;
	if(u!=v){
		printf("-1");
		return 0;
	}
	u=v=0;i=j=1;
	while(i<=n||j<=m){
		if(u<v)
			u+=a[i++];
		else
			v+=b[j++];
		if(u==v)
			u=v=0,s++;
	}
	printf("%d",s);
}