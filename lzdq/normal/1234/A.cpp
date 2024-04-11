#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=105;
int n,q;
int a[MAXN],sum;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		sum=0;
		int l=10000001,r=0;
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			sum+=a[i];
			l=min(l,a[i]);
			r=max(r,a[i]);
		}
		for(int i=l;i<=r;i++)
			if(i*n>=sum){
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}