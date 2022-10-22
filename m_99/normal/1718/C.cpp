#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
#define InfL 4000000000000000001

int main() {
	


	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,q;
		cin>>n>>q;
		
		vector<int> ys;
		for(int i=1;i*i<=n;i++){
			if(n%i==0){
				ys.push_back(i);
				if(i*i!=n)ys.push_back(n/i);
			}
		}
		
		vector<long long> a(n);
		rep(i,n)scanf("%lld",&a[i]);
		vector<long long> x(q);
		vector<int> p(q);
		rep(i,q){
			scanf("%d %lld",&p[i],&x[i]);
			p[i]--;
		}
		
		vector<long long> ans(q+1,0);
		rep(i,ys.size()){
			if(ys[i]==n)continue;
			vector<long long> b = a;
			vector<long long> sum(ys[i],0);
			vector<int> last(ys[i],-1);
			priority_queue<pair<long long,pair<int,int>>> Q;
			rep(j,n){
				sum[j%ys[i]] += a[j];
			}
			rep(j,sum.size()){
				Q.emplace(sum[j],make_pair(j,-1));
			}
			//cout<<ys[i]<<','<<Q.top().first<<endl;
			ans[0] = max(ans[0],Q.top().first*ys[i]);
			//cout<<i<<endl;
			rep(j,q){
				int jj = p[j]%ys[i];
				sum[jj] += x[j] - b[p[j]];
				b[p[j]] = x[j];
				last[jj] = j;
				Q.emplace(sum[jj],make_pair(jj,j));
				while(true){
					if(last[Q.top().second.first]==Q.top().second.second){
						ans[j+1] = max(ans[j+1],Q.top().first*ys[i]);
						break;
					}
					else{
						Q.pop();
					}
				}
			}
			
		}
		rep(i,q+1){
			printf("%lld\n",ans[i]);
		}
		
	}
	
    return 0;
}