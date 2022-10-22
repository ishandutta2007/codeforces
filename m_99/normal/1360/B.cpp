#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		vector<int> s(n);
		for(int i=0;i<n;i++)scanf("%d",&s[i]);
		
		sort(s.begin(),s.end());
		
		int ans = Inf;
		for(int i=0;i<n-1;i++){
			ans = min(ans,s[i+1]-s[i]);
		}
		cout<<ans<<endl;
	}
	
	return 0;	
}