#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		long long x;
		cin>>x;
		
		string s;
		cin>>s;
		
		vector<pair<char,long long>> C;
		rep(i,s.size()){
			if(C.size()==0||C.back().first!=s[i]){
				C.emplace_back(s[i],1);
			}
			else{
				C.back().second++;
			}
		}
		
		vector<long long> v;
		rep(i,C.size()){
			if(C[i].first=='*')v.push_back(C[i].second * k);
		}
		reverse(v.begin(),v.end());
		
		vector<long long> t(v.size());
		x--;
		rep(i,v.size()){
			t[i] = x % (v[i]+1);
			x /= (v[i]+1);
		}
		
		reverse(t.begin(),t.end());
		int cur = 0;
		string ans = "";
	//	cout<<'a'<<endl;
		rep(i,C.size()){
			//cout<<C[i].first<<','<<C[i].second<<endl;
			if(C[i].first=='a'){
				rep(j,C[i].second)ans += 'a';
			}
			else{
				rep(j,t[cur])ans += 'b';
				cur++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}