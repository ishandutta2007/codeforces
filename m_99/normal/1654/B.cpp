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
		//cin>>n;
		string s;
		cin>>s;
		
		vector<int> c(26,0);
		rep(i,s.size()){
			c[s[i]-'a']++;
		}
		rep(i,s.size()){
			c[s[i]-'a']--;
			if(c[s[i]-'a']==0){
				cout<<s.substr(i)<<endl;
				break;
			}
		}
		
		
	}
	
	return 0;
}