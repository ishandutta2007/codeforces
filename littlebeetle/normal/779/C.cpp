#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
struct p{
	int x,y;
	bool operator<(p const &k)const{
		return k.x-k.y>x-y;
	}
}a[N];
int n,m,i,s;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i].x);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i].y);
	sort(a+1,a+n+1);
	for(i=1;i<=m;i++)
		s+=a[i].x;
	for(;i<=n&&a[i].x<a[i].y;i++)
		s+=a[i].x;
	for(;i<=n;i++)
		s+=a[i].y;
	printf("%d",s);
}