#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000000000000


int main(){
	
	
	int _t;
	cin>>_t;
	vector<string> t = {"00","52","05","57"};
	rep(_,_t){
		string s;
		cin>>s;
		
		reverse(s.begin(),s.end());
		int ans = 100000;
		
		rep(i,s.size()){
			for(int j=i+1;j<s.size();j++){
				rep(k,4){
					if(t[k][0]==s[i]&&t[k][1]==s[j]){
						ans = min(ans,j-1);
					}
				}
				
			}
		}cout<<ans<<endl;
		
	}
	
	return 0;
}