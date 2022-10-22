#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int a,b;
		scanf("%d %d",&a,&b);
		int t = max(min(a,b)*2,max(a,b));
		printf("%d\n",t*t);
	}
	
	return 0;	
}