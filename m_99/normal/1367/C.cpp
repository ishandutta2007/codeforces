#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int get(int n,int k){
	if(n<=0)return 0;
	return n/(k+1);
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		string s;
		cin>>s;
		
		vector<pair<int,int>> p;
		rep(i,s.size()){
			int b = s[i]-'0';
			if(p.size()==0||p.back().first!=b){
				p.emplace_back(b,1);
			}
			else{
				p.back().second++;
			}
		}
		
		int ans = 0;
		
		rep(i,p.size()){
			if(p[i].first==0){
				int c = p[i].second;
				if(p.size()==1){
					ans += 1 + get(c-1,k);
				}
				else if(i!=0&&i+1!=p.size()){
					ans += get(c-k,k);
				}
				else{
					ans += get(c,k);
				}
				
			}
		}
		cout<<ans<<endl;
	}
		
	
	return 0;
}