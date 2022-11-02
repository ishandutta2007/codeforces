#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
struct p{
	int d,x;
	bool operator<(const p &u)const{
		return u.x>x;
	}
}a[N];
int n,i,f[N],t;
long long s;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i].x),a[i].d=i;
	sort(a+1,a+n+1);
	for(i=1;i<n;i++)
		s+=a[i].x;
	for(i=1;i<n;i++)
		if(s-a[i].x==a[n].x)
			f[++t]=a[i].d;
	if(a[n-1].x==s-a[n-1].x)
		f[++t]=a[n].d;
	printf("%d\n",t);
	for(i=1;i<=t;i++)
		printf("%d ",f[i]);
	return 0;
}