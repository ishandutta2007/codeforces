#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int n,m,i,a[N],l,r;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(l=r=1;r<=n;r++){
		while(a[l]<a[r]-5)
			l++;
		m=max(m,r-l+1);
	}
	printf("%d",m);
}