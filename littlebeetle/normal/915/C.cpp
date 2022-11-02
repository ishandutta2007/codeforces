#include<cstdio>
#include<algorithm>
using namespace std;
const int N=102;
long long a,b;
int A[N],B[N],u[N],n,m,i,j;
bool cmp(int x,int y){
	return x>y;
}
void out(){
	for(i=1;i<=n;i++)
		if(!u[i])
			printf("%d",A[i]);
	//while(1);
}
bool ok(int i){
	int k;int l=i-1;
	for(k=n;k;k--)
		if(!u[k]){
			if(A[k]>B[l])
				return 0;
			if(A[k]<B[l])
				return 1;
			l--;
		}
	return 1;
}
int main(){
	scanf("%lld%lld",&a,&b);
	while(a)
		A[++n]=a%10,a/=10;
	while(b)
		B[++m]=b%10,b/=10;	
	sort(A+1,A+n+1,cmp);
	if(n<m){
		out();
		//while(1);
		return 0;
	}
	for(i=n;i;i--){
		for(j=1;j<=n;j++){
			if(!u[j]&&A[j]<B[i])
				break;
			if(!u[j]&&A[j]==B[i]){
				u[j]=1;
				if(ok(i))
					break;
				u[j]=0;
			}
		}
			u[j]=1;
		printf("%d",A[j]);
		if(A[j]<B[i]){
			out();
			//while(1);
			return 0;
		}
	}
	//while(1);
}