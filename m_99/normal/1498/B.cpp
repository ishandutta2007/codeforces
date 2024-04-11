#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		int n,W;
		cin>>n>>W;
		
		multiset<int> S;
		rep(i,n){
			int x;
			scanf("%d",&x);
			S.insert(x);
		}
		
		int ans = 0;
		int cur = 0;
		while(S.size()!=0){
			auto it = S.upper_bound(cur);
			if(it==S.begin()){
				cur = W;
				ans++;
				continue;
			}
			it--;
			cur -= *it;
			S.erase(it);
		}
		
		printf("%d\n",ans);
		
	}
	
	
	
	
    return 0;
}