#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000



int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		
		vector<int> a(n),b(m);
		for(int j=0;j<n;j++)scanf("%d",&a[j]);
		for(int j=0;j<m;j++)scanf("%d",&b[j]);
		
		reverse(a.begin(),a.end());
		
		long long ans = 0;
		set<int> S;
		for(int j=0;j<b.size();j++){
			if(S.count(b[j])){
				S.erase(b[j]);
				ans ++;
			}
			else{
				long long X = S.size();
				while(a.back()!=b[j]){
					S.insert(a.back());
					X ++;
					a.pop_back();
				}
				a.pop_back();
				ans += X*2+1;
			}
		}
		cout<<ans<<endl;
		
	}
	

    return 0;
}