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
		int n = s.size();
		string t = "";
		while(t.size()<s.size()){
			t.insert(t.begin(),s.back());
			s.pop_back();
		}
		cout<<(s==t?"YES":"NO")<<endl;
	}
	
	return 0;
}