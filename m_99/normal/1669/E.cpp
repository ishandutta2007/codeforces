#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		vector cnt(11,vector<long long>(11,0));
		rep(i,n){
			string s;
			cin>>s;
			cnt[s[0]-'a'][s[1]-'a']++;
		}
		long long ans = 0;
		rep(i,11){
			rep(j,11){
				for(int k=j+1;k<11;k++){
					ans += cnt[i][j] * cnt[i][k];
					ans += cnt[j][i] * cnt[k][i];
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
    return 0;
}