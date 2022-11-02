#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,m,k,a[N],b[N],i,j,l,r,mid,s;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<n;i++)
		b[i]=a[i+1]-a[i]-1;
	sort(b+1,b+n);
	for(i=1;i<=n-k;i++)
		s+=b[i];
	printf("%d",s+n);
}