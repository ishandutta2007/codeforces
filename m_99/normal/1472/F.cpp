#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector<int> r(m),c(m);
		rep(i,m){
			scanf("%d %d" ,&r[i],&c[i]);
			
			r[i]--;
		}
		r.push_back(0);
		c.push_back(0);
		c.push_back(0);
		r.push_back(1);
		r.push_back(0);
		c.push_back(n+1);
		r.push_back(1);
		c.push_back(n+1);
		
		vector<int> t;
		rep(i,c.size()){
			t.push_back(c[i]);
		}
		
		sort(t.begin(),t.end());
		t.erase(unique(t.begin(),t.end()),t.end());
		
		vector<vector<int>> X(t.size());
		
		rep(i,r.size()){
			int idx = distance(t.begin(),lower_bound(t.begin(),t.end(),c[i]));
			X[idx].push_back(r[i]);
		}
		
		vector<string> S(2,"");
		rep(i,X.size()){
			S[0] += '0';
			S[1] += '0';
			rep(j,X[i].size()){
				S[X[i][j]].back() = '1';
			}
			if(1+i!=X.size()&&(t[i+1]-t[i]+1)%2==1){
				S[0] += '0';
				S[1] += '0';
			}
		}
		
	//	cout<<S[0]<<endl;
		//cout<<S[1]<<endl;
		
		
		vector<bool> dp(4,false);
		dp.back() = true;
		rep(i,S[0].size()-1){
			vector<bool> ndp(4,false);
			rep(j,4){
				if(dp[j]==false)continue;
				
				int nj = 0;
				if(!(j&1)){
					if(S[0][i+1]=='1')continue;
					else nj |= 1;
				}
				if(!(j&2)){
					if(S[1][i+1]=='1')continue;
					else nj |= 2;
				}
				if(S[0][i+1]=='1')nj |= 1;
				if(S[1][i+1]=='1')nj |= 2;
				
				ndp[nj] = true;
				if(nj==0)ndp[3] = true;
				
			}
			//rep(j,4)cout<<ndp[j]<<',';
			//cout<<endl;
			swap(dp,ndp);
		}
		
		if(dp.back())printf("YES\n");
		else printf("NO\n");
		
	}
	
    return 0;
}