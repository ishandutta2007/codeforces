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
		bool f = false;
		rep(i,n-1){
			int x = s[i]-'0';
			x += s[i+1]-'0';
			if(x>=10)f = true;
		}
		if(f){
			for(int i=n-2;i>=0;i--){
				int x = s[i]-'0';
				x += s[i+1]-'0';
				if(x>=10){
					s[i] = '1';
					s[i+1] ='0' + ( x%10);
					break;
				}
			}
		}
		else{
			int x = s[0]-'0';
			x += s[1]-'0';
			rep(i,2)s.erase(s.begin());
			s.insert(s.begin(),'0' + x);
		}
		cout<<s<<endl;
		
	}
	
	return 0;
}