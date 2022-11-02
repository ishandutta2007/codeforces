#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int n,a[N],i,j;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=j=1;;i++){
		while(j<=n&&a[j]<i)
			j++;
		if(j>n){
			printf("%d",i-1);
			//while(1);
			return 0;
		}
		j++;
	}
	return 0;
}