#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int get(string s,string t){
	int ret = s.size() + t.size();
	int cur = 0;
	rep(i,s.size()){
		if(cur!=t.size()){
			if(s[i]==t[cur]){
				cur++;
			}
		}
	}
	ret -= cur*2;
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	vector<string> S;
	
	for(long long i=0;i<=62;i++){
		S.push_back(to_string((1LL<<i)));
	}
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		string s = to_string(n);
		
		int ans = Inf;
		rep(i,S.size()){
			ans = min(ans,get(s,S[i]));
		}
		printf("%d\n",ans);
		
	}
	
	return 0;
}