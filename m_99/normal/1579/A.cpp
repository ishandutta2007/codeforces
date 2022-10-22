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
		vector<int> cnt(3,0);
		rep(i,s.size()){
			cnt[s[i]-'A']++;
		}
		
		cnt[1] -= cnt[0];
		cnt[0] = 0;
		if(cnt[1]!=cnt[2])printf("NO\n");
		else printf("YES\n");
		
	}
	
	return 0;
}