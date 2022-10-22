#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 10000000000000000

int main() {
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n,k;
		cin>>n>>k;
		string S;
		cin>>S;
		vector<vector<int>> cnt((k+1)/2,vector<int>(26,0));
		for(int i=0;i<n;i+=k){
			for(int j=0;j<k/2;j++){
				char x = S[i+j];
				cnt[j][x-'a']++;
				x = S[i+k-1-j];
				cnt[j][x-'a']++;
			}
			if(k%2==1){
				char x = S[i+k/2];
				cnt[k/2][x-'a']++;
			}
		}
		int ans = 0;
		for(int i=0;i<cnt.size();i++){
			int sum = 0;
			int maxi = 0;
			for(int j=0;j<26;j++){
				sum += cnt[i][j];
				maxi = max(maxi,cnt[i][j]);
			}
			ans += sum-maxi;
		}
		cout<<ans<<endl;
	}
	
    return 0;
}