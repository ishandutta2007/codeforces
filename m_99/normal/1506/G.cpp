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
		vector<vector<int>> nxt(n+1,vector<int>(26,Inf));
		for(int i=s.size()-1;i>=0;i--){
			nxt[i] = nxt[i+1];
			nxt[i][s[i]-'a'] = i;
		}
		
		vector<bool> used(26,false);
		int cnt = 0;
		rep(i,26){
			if(nxt[0][i]==Inf)used[i] = true;
			else cnt++;
		}
		int cur = 0;
		string ans = "";
		
		rep(i,cnt){
			for(int j=25;j>=0;j--){
				if(used[j])continue;
				int nx = nxt[cur][j];
				bool f = true;
				rep(k,j){
					if(used[k])continue;
					if(nxt[nx][k]==Inf){
						f=false;
						break;
					}
				}
				if(f){
					ans += 'a'+j;
					used[j] = true;
					cur = nxt[cur][j];
					break;
				}
				
			}
		}
		
		cout<<ans<<endl;
		
	}

    return 0;
}