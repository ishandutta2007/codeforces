#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		string s;
		cin>>s;
		
		vector<long long> cnt(n+1,0);
		rep(i,m){
			int p;
			scanf("%d",&p);
			cnt[p] ++;
		}
		cnt.back()++;
		for(int i=n-1;i>=0;i--)cnt[i] += cnt[i+1];
		
		vector<long long> ans(26,0);
		rep(i,n){
			ans[s[i]-'a'] += cnt[i+1];
		}
		
		rep(i,26){
			if(i!=0)printf(" ");
			printf("%lld",ans[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}