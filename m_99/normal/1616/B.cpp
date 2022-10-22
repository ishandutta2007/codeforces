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
		string s;
		cin>>s;
		
		string ans = "";
		rep(i,s.size()){
			if(ans.size()==0 || (ans.back()>s[i])){
				ans += s[i];
			}
			else if(ans.back()==s[i]){
				if(ans[0] > s[i]){
					ans += s[i];
				}
				else break;
			}
			else break;
		}
		cout<<ans;
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
		
	}
	
	return 0;
}