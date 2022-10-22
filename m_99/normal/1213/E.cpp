#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	int n;
	cin>>n;
	string temp = "abc";
	
	vector<string> ans;
	
	do{
		string t = "";
		rep(i,n){
			rep(j,3){
				t += temp[j];
			}
		}
		ans.push_back(t);
		t = "";
		rep(i,3){
			rep(j,n){
				t += temp[i];
			}
		}
		ans.push_back(t);
		
	}
	while(next_permutation(temp.begin(),temp.end()));
	
	string s,t;
	cin>>s>>t;
	
	rep(i,ans.size()){
		temp = ans[i];
		bool f = true;
		rep(j,3*n-1){
			if(temp.substr(j,2)==s){
				 f = false;
				 break;
			}
			if(temp.substr(j,2)==t){
				f = false;
				break;
			}
		}
		if(f){
			cout<<"YES"<<endl;
			cout<<temp<<endl;
			return 0;
		}
	}
	
	cout<<"NO"<<endl;
	
	return 0;
}