#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
int n,i,j,a[N],b[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<n;i++)
		scanf("%1d",b+i);
	for(i=1;i<n;i++)
		if(b[i]&&!b[i-1]){
			j=i;
			while(b[j])
				j++;
			sort(a+i,a+j+1);
		}
	for(i=1;i<=n;i++)
		if(a[i]!=i){
			printf("NO");
			return 0;
		}
	printf("YES");
}