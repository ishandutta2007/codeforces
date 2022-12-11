#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int z=0;
	for(;z*z<n;z++);
	int ok=0;
	for(int i=n/z;i>=0;i--)
		for(int j=i*z+1;j<=min(n,(i+1)*z);j++){
			if(ok)printf(" ");
			ok=1;
			printf("%d",j);
		}
	printf("\n");
}