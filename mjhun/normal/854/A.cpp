#include <iostream>
using namespace std;

int gcd(int a, int b){return b?gcd(b,a%b):a;}

int main(){
	int n;
	scanf("%d",&n);
	int r0,r1;
	for(int i=1;i<=n;++i)if(i>=n-i&&gcd(i,n-i)==1){
		r0=n-i;r1=i;break;
	}
	printf("%d %d\n",r0,r1);
	return 0;
}