#include<cstdio>

using namespace std;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=k;
	for(int i=1;i<=n;i++){
		int z;
		scanf("%d",&z);
		z%=k;
		ans=gcd(ans,z);
	}
	printf("%d\n",k/ans);
	for(int i=0;i<k/ans;i++)
		printf("%d%c",i*ans,i==k/ans?'\n':' ');
}