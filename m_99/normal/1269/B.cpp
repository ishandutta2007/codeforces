#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

	

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<int> a(n),b(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	int ans = 1000000005;
	
	for(int i=0;i<n;i++){
		int x = b[0] - a[0];
		if(x < 0)x+=m;
		
		bool f = true;
		for(int j=0;j<n;j++){
			if((a[j] + x)%m != b[j])f=false;
		}
		
		if(f){
			ans = min(ans,x);
		}
		
		x = a[0];
		a.erase(a.begin());
		a.push_back(x);
		
		
		
	}
	cout<<ans<<endl;
	
	return 0;
}