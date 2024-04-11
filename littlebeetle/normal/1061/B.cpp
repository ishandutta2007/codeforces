#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,m,i,j,a[N];
long long s,p;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),s+=a[i];
	sort(a+1,a+n+1);
	j=a[n];
	for(i=n;i&&j;i--){
		if(j>a[i-1]){
			p+=j-a[i-1];
			j=a[i-1];
		}
		else
			p++,j--;
	}
	p+=i;
	printf("%I64d",s-p);
}