#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		long long x,y;
		cin>>x>>y;
		
		string s,t;
		cin>>s>>t;
		vector<int> ii;
		rep(i,n){
			if(s[i]!=t[i]){
				ii.push_back(i);
			}
		}
		if(ii.size()%2==1){
			cout<<-1<<endl;
			continue;
		}
		long long ans = 0;
		if(ii.size()==2){
			if(ii[0]+1==ii[1]){
				ans = min(x,y*2);
			}
			else ans = y;
		}
		else{
			ans = ii.size()/2;
			ans *= y;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}