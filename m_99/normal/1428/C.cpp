#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){	
	
	int t;
	cin>>t;
	
	rep(_,t){
		
		string s;
		cin>>s;
		
		vector<pair<int,char>> P;
		
		rep(i,s.size()){
			if(P.size()==0 || P.back().second!=s[i]){
				P.emplace_back(1,s[i]);
			}
			else{
				P.back().first++;
			}
		}
		
		int ans = 0;
		
		while(P.size()!=0){
			if(P.back().second=='A'){
				ans += P.back().first;
				P.pop_back();
				continue;
			}
			
			if(P.size()==1){
				ans += P.back().first%2;
				break;
			}
			pair<int,char> y = P.back();
			P.pop_back();
			pair<int,char> x = P.back();
			P.pop_back();
			
			if(x.second=='B'){
				x.first += y.first;
				P.push_back(x);
				continue;
			}
			
			int z = min(x.first,y.first);
			y.first -= z;
			x.first -= z;
			if(x.first>0)P.push_back(x);
			if(y.first>0)P.push_back(y);
			
		}
		
		cout<<ans<<endl;
		
	}
	
    return 0;
}