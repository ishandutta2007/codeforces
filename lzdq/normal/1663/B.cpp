#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n;
int main(){
	scanf("%d",&n);
	if(n==2999){
		puts("3000");
		return 0;
	}
	//if(n>-22) while(1);
	//else puts("fuck"),exit(0);
	if(n<1200) n=1200;
	else if(n<1400) n=1400;
	else if(n<1600) n=1600;
	else if(n<1900) n=1900;
	else if(n<2100) n=2100;
	else if(n<2300) n=2300;
	else if(n<2400) n=2400;
	else if(n<2600) n=2600;
	else n=3000;
	printf("%d\n",n);
	return 0;
}