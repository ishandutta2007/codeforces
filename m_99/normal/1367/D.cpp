#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		int n = s.size();
		int m;
		cin>>m;
		vector<int> b(m);
		rep(i,m){
			cin>>b[i];
		}
		
		string ans(m,'0');
		
		vector<int> inds;
		vector<int> cnt(26,0);
		rep(i,n){
			cnt[s[i]-'a']++;
		}
		
		for(int i=25;i>=0;i--){
			vector<int> pos;
			rep(j,m){
				if(ans[j]!='0')continue;
				int sum = 0;
				rep(k,inds.size()){
					sum += abs(inds[k] - j);
				}
				if(sum == b[j])pos.push_back(j);
				
			}
			if(pos.size() > cnt[i])continue;
			rep(j,pos.size()){
				ans[pos[j]] = 'a'+i;
				inds.push_back(pos[j]);
			}
			
		}
		
		cout<<ans<<endl;
	}
		
	
	return 0;
}