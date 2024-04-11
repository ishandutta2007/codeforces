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
		vector<pair<long long,long long>> pos(n);
		rep(i,n)scanf("%lld",&pos[i].first);
		rep(i,n)scanf("%lld",&pos[i].second);
		
		
		
		
		sort(pos.begin(),pos.end());
		if(pos[0].first!=1){
			pos.insert(pos.begin(),make_pair(1LL,1LL));
		}
		
		long long ans = 0LL;
		rep(i,pos.size()-1){
			
			int r0 = pos[i].first,c0 = pos[i].second,r1 = pos[i+1].first,c1 = pos[i+1].second;
			
			if((r0+c0)%2==1){
				
				long long t = (r1-r0) - (c1-c0);
				ans += (t+1)/2;
				
			}
			else{
				long long t = (r1-r0) - (c1-c0);
				if(t==0){
					ans += r1-r0;
					continue;
				}
				r0++;
				t = (r1-r0) - (c1-c0);
				ans += (t+1)/2;
				
				
			}
			
		}
		printf("%lld\n",ans);
		
	}

    return 0;
}