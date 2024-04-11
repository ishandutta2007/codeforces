#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
int m,n,a[N],b,i,j,k,x;
long long sum,ans=1ll<<50;
int abs(int x){
	return x>0?x:-x;
}
int main(){
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		if(x)
			a[++n]=i;
	}
	for(i=2;i<=n;i++)
		if(n%i==0){
			sum=0;
			for(k=1;k<n;k+=i){
				b=a[(k+k+i-1)/2];
				for(j=0;j<i;j++)
					sum+=abs(b-a[k+j]);
			}
			if(sum<ans)
				ans=sum;
		}
	printf("%lld",ans==(1ll<<50)?-1:ans);
		//while(1);
}