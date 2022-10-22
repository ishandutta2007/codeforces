#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		int n = s.size();
		vector<int> cnt(10,0);
		int m = Inf32;
		for(int i=n-1;i>=0;i--){
			int b = s[i] - '0';
			if(m < b){
				cnt[min(b+1,9)]++;
			}
			else{
				m = min(b,m);
				cnt[b]++;
			}
		}
		string ans = "";
		rep(i,10){
			rep(j,cnt[i])ans += '0'+i;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}