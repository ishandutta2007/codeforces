#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
 
 
int main(){
	
	int _t;
	cin>>_t;
//	_t = 1;
	rep(_,_t){
		
		int n,a,f;
		scanf("%d",&n);
		vector<int> cnt(n+1,0);
		vector<int> c(n+1,0);
		rep(i,n){
			scanf("%d %d",&a,&f);
			cnt[a]++;
			if(f){
				c[a]++;
			}
		}
		vector<vector<int>> ncnt(n+1);
		rep(i,n+1){
			ncnt[cnt[i]].push_back(c[i]);
		}
		int ans = 0;
		int Ans = 0;
		priority_queue<int> Q;
		for(int i=n;i>=1;i--){
			rep(j,ncnt[i].size()){
				Q.push(ncnt[i][j]);
			}
			if(Q.size()>0){
				Ans += i;
				ans += min(i,Q.top());
				Q.pop();
			}
		}
		printf("%d %d\n",Ans, ans);
		
	}
	
	return 0;
}