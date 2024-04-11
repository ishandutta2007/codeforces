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
		scanf("%d",&n);
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		int ans = 0;
		rep(i,5){
			vector<int> t(n,0);
			
			rep(j,n){
				rep(k,s[j].size()){
					if(s[j][k]-'a'==i)t[j]++;
					else t[j]--;
				}
			}
			
			sort(t.rbegin(),t.rend());
			int sum = 0;
			rep(j,n){
				sum += t[j];
				if(sum > 0){
					ans = max(ans,j+1);
				}
			}
		}
		
		printf("%d\n",ans);
		
		
	}
	
	return 0;
}