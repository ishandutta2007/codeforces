#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
#define InfL 4000000000000000001

int main() {	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		
		int cnt = 0;
		rep(i,n){
			rep(j,m){
				if(s[i][j]=='1')cnt++;
			}
		}
		
		int mini = Inf;
		rep(i,n-1){
			rep(j,m-1){
				int cc =  0;
				rep(k,2){
					rep(l,2){
						if(s[i+k][j+l]=='1')cc++;
					}
				}
				mini = min(mini,cc);
			}
		}
		mini--;
		mini = max(mini,1);
		int ans = 0;
		while(cnt!=0){
			cnt -= mini;
			mini = 1;
			ans++;
		}
		cout<<ans<<endl;
	}
	
    return 0;
}