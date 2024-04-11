#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		
		while(s.size()!=0){
			int sz = s.size();
			char c = 'a' + sz - 1;
			if(s[0]==c){
				s.erase(s.begin());
				continue;
			}
			if(s.back()==c){
				s.pop_back();
				continue;
			}
			break;
		}
		if(s.size()==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}