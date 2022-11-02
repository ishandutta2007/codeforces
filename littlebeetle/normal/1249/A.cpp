#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int q,n,i,a[N],t;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		t=0;
		for(i=1;i<n;i++)
			if(a[i]+1==a[i+1])
				t=1;
		printf("%d\n",t+1);
	}
}