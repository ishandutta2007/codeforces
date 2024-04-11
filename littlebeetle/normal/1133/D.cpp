#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
struct p{
	int a,b;
	long double c;
	bool operator<(const p &k)const{
		return k.c>c;
	}
	bool operator==(const p &k)const{
		return 1ll*k.a*b==1ll*a*k.b;
	}
}x[N];
int n,m,i,A[N],B[N],ans1,ans2,sum;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",A+i);
	for(i=1;i<=n;i++)scanf("%d",B+i);
	for(i=1;i<=n;i++)
		if(A[i]==0){
			if(B[i]==0)
				ans1++;
		}
		else{
			if(B[i]<=0)
				A[i]=-A[i],B[i]=-B[i];
			x[++m]=(p){A[i],B[i],((long double)B[i])/A[i]};
		}
	sort(x+1,x+m+1);
	for(i=1;i<=m;i++)
		if(x[i]==x[i-1])
			sum++;
		else
			ans2=max(ans2,sum),sum=1;
		ans2=max(ans2,sum);
	printf("%d",ans1+ans2);
}