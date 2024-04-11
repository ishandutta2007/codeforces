#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		
		vector<int> cnt(26,0);
		rep(i,s.size()){
			cnt[s[i]-'a']++;
		}
		
		int r = 0,b = 0;
		int x = 0;
		rep(i,26){
			if(cnt[i]>=2){
				r++;
				b++;
			}
			if(cnt[i]==1)x++;
		}
		r += x/2;
		
		cout<<r<<endl;
			
		
	}
	
	return 0;
}