#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		
		int n;
		scanf("%d",&n);
		vector<long long> a(n);
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		
		
		bool f = true;
		for(int i=1;i<n;i++){
			if(a[i]!=a[0]){
				f=false;
				break;
			}
		}
		
		if(f){
			printf("%d\n",n);
		}
		else printf("1\n");
		
	}
	
	return 0;
}