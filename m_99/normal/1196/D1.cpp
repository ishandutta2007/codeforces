#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		
		string s;
		cin>>s;
		
		vector<int> ind(n);
		rep(i,n){
			if(s[i]=='R')ind[i] = 0;
			if(s[i]=='G')ind[i] = 2;
			if(s[i]=='B')ind[i] = 1;
		}
		
		vector<int> cur(3,0);
		int ans = Inf;
		rep(i,n){
			cur[(ind[i]+i)%3]++;
			if(i-k>=0){
				cur[(ind[i-k]+(i-k))%3]--;
			}
			rep(j,3){
				ans = min(ans,k - cur[j]);
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}