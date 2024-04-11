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
		cin>>n;
		
		vector<string> t(n-2);
		rep(i,n-2)cin>>t[i];
		
		string ans = t[0];
		for(int i=1;i<t.size();i++){
			if(ans.back() == t[i][0])ans += t[i][1];
			else ans += t[i];
		}
		if(ans.size()!=n)ans += 'a';
		cout<<ans<<endl;
		
		
	}
	
	return 0;
}