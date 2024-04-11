#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	rep(_,_t){
		int n,m;
		cin>>n>>m;
		
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		string t;
		cin>>t;
		
		vector<pair<int,int>> ind2(100,make_pair(-1,-1)),ind3(1000,make_pair(-1,-1));
		
		rep(i,n){
			int sz = s[i].size();
			rep(j,sz-1){
				int cur = 0;
				rep(k,2){
					cur *= 10;
					cur += s[i][j+k] - '0';
				}
				ind2[cur] = make_pair(i,j);
			}
			rep(j,sz-2){
				int cur = 0;
				rep(k,3){
					cur *= 10;
					cur += s[i][j+k] - '0';
				}
				ind3[cur] = make_pair(i,j);
			}
		}
		
		vector<int> dp(m+1,-1);
		dp[0] = 0;
		
		rep(i,m){
			if(dp[i]==-1)continue;
			for(int j=2;j<=3;j++){
				if(i+j>m)continue;
				int cur = 0;
				rep(k,j){
					cur *= 10;
					cur += t[i+k]-'0';
				}
				if(j==2){
					if(ind2[cur].first!=-1)dp[i+2] = i;
				}
				else{
					if(ind3[cur].first!=-1)dp[i+3] = i;
				}
				
			}
			
		}
		
		if(dp.back()==-1){
			printf("-1\n");
			
		}
		else{
			vector<int> ll,rr,ii;
			int pos = m;
			while(pos != 0){
			//	cout<<pos<<endl;
				int L = dp[pos];
				int R = pos;
				int cur = 0;
				for(int i=L;i<R;i++){
					cur *= 10;
					cur += t[i]-'0';
				}
				if(R-L==2){
					ll.push_back(ind2[cur].second);
					ii.push_back(ind2[cur].first);
				}
				else{
					ll.push_back(ind3[cur].second);
					ii.push_back(ind3[cur].first);
				}
				rr.push_back(ll.back() + (R-L) - 1);
				pos = dp[pos];
			}
			reverse(ll.begin(),ll.end());
			reverse(rr.begin(),rr.end());
			reverse(ii.begin(),ii.end());
			printf("%d\n",ll.size());
			rep(i,ll.size()){
				printf("%d %d %d\n",ll[i]+1,rr[i]+1,ii[i]+1);
			}
		}
		
		
		
	}
	
	return 0;
}