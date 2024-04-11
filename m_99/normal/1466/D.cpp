#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		vector<long long> w(n);
		rep(i,n){
			scanf("%lld",&w[i]);
		}
		
		vector<pair<int,int>> cnt(n,make_pair(0,0));
		rep(i,n)cnt[i].first = w[i];
		rep(i,n-1){
			int a,b;
			scanf("%d %d",&a,&b);
			a--;b--;
			
			cnt[a].second++;
			cnt[b].second++;
		}
		
		long long cur = 0LL;
		
		rep(i,n){
			cur += w[i];
			cnt[i].second --;
		}
		
		sort(cnt.begin(),cnt.end());
		
		rep(i,n-1){
			if(i!=0){
				while(cnt.size()>0 && cnt.back().second==0)cnt.pop_back();
				if(cnt.size()>0){
					cur += cnt.back().first;
					cnt.back().second--;	
				}				
				printf(" ");
			}
			printf("%lld",cur);

		}
		printf("\n");
		
	}
	
    return 0;
}