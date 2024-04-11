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
		
		vector<pair<int,int>> a(n);
		rep(i,n){
			cin>>a[i].first;
			a[i].second = a[i].first;
		}
		
		vector<int> b;
		int g = 0;
		while(a.size()>0){
			sort(a.begin(),a.end());
			b.push_back(a.back().second);
			g = gcd(g,a.back().second);
			a.pop_back();
			rep(i,a.size()){
				a[i].first = gcd(a[i].first,g);
			}
		}
		
		rep(i,b.size()){
			if(i!=0)cout<<' ';
			cout<<b[i];
		}
		cout<<endl;
		
	}
	
    return 0;
}