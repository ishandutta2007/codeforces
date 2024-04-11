#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		
		vector<int> cnt(n,0);
		int ans = 0;
		rep(i,n){
			rep(j,n){
				int tt = i-j;
				if(tt<0)tt += n;
				if(s[i][j]=='1'){
					ans++;
					cnt[tt]--;
				}
				else{
					cnt[tt]++;
				}
			}
		}
		{
			int m = Inf;
			rep(i,n){
				m = min(m,cnt[i]);
			}
			ans += m;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}