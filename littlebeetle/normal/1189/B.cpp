#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
struct p{
	int x,y;
}a[N];
int n,i;
bool cmp(p u,p v){
	return u.x<v.x;
}
bool cmp2(p u,p v){
	if(u.y!=v.y)return u.y>v.y;
	if(u.y)return u.x<v.x;
	return u.x>v.x;
}	
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i].x);
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
		a[i].y=i%2;
	sort(a+1,a+n+1,cmp2);
	for(i=1;i<=n;i++)
		a[n+i]=a[i];
	for(i=2;i<n*2;i++)
		if(a[i].x>=a[i-1].x+a[i+1].x){
			printf("NO");
			return 0;
		}
	printf("YES\n");
	for(i=1;i<=n;i++)
		printf("%d ",a[i].x);
}