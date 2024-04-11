#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		string s;
		cin>>n>>s;
		
		int mini = 0;
		int cur = 0;
		rep(i,n){
			if(s[i]==')')cur--;
			else cur++;
			mini = min(mini,cur);
		}
		
		cout<<abs(mini)<<endl;
		
		
	}
	
	return 0;
}