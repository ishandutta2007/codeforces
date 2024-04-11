#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
struct p{
	int l,r;
	bool operator<(const p &x)const{
		return x.l>l;
	}
}a[N];
int n,i,x=-1,y=-1;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		if(a[i].l<=x){
			printf("NO");
			return 0;
		}
		x=a[i].r;
		if(x>y)
			x^=y^=x^=y;
	}
	printf("YES");
}