#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int main(){

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		scanf("%d",&n);
		
		vector<long long> a(n);
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if(i!=0)a[i] += a[i-1];
		}
		
		long long mini = 0;
		long long ans = -Inf;
		
		for(int i=0;i<n-1;i++){
			ans = max(ans,a[i]-mini);
			mini = min(mini,a[i]);
		}
		mini = a[0];
		for(int i=1;i<n;i++){
			ans = max(ans,a[i]-mini);
			mini = min(mini,a[i]);
		}
		if(a.back() > ans){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		
	}
		
	
	return 0;
}