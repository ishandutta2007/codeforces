#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

bool check(string s){
	while(s.back()=='0'){
		s.pop_back();
	}
	int n = s.size();
	return s==string(n,'1');
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		string x,y;
		cin>>x>>y;
		
		int ans = 0;
		int state = -1;
		while(x.size()>0){
			if(x.back()!=y.back()){
				ans += 2;
				state = -1;
			}
			else{
				if(x.back()=='0'){
					ans++;
					if(state==1){
						ans++;
						state = -1;
					}
					else{
						state = 0;
					}
				}
				else{
					if(state==0){
						ans++;
						state = -1;
					}
					else{
						state = 1;
					}
				}
			}
			x.pop_back();
			y.pop_back();
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}