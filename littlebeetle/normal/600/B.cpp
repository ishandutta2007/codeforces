#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000020;
int n,m,i,a[N],l,r,mid,x;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		l=0;r=n;
		while(l<r){
			mid=l+r+1>>1;
			if(a[mid]<=x)
				l=mid;
			else
				r=mid-1;
		}
		printf("%d ",l);
	}
	//while(1);
}