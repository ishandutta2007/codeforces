#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		int n;
		cin>>n;
		vector<int> a(n);
		int c0 = 0;
		rep(i,n){
			cin>>a[i];
			if(a[i]==0)c0++;
		}
		vector<int> ans;
		if(c0*2>=n){
			ans.resize(n/2,0);
		}
		else{
			ans.resize(n/2,1);
			if(ans.size()%2==1)ans.push_back(1);
		}
		
		cout<<ans.size()<<endl;
		rep(i,ans.size()){
			if(i!=0)cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
	}
	
    return 0;
}