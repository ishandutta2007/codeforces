#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		vector cnt(2,0);
		rep(i,s.size())cnt[s[i]-'0']++;
		
		int ans = 0;
		if(cnt[0]==cnt[1])ans = cnt[0]-1;
		else ans = min(cnt[0],cnt[1]);
		
		cout<<ans<<endl;
		
		
		
	}
	
	return 0;
}