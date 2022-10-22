#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

int main(){
	
	int n;
	cin>>n;
	
	vector<long long> a(n),b(n);
	rep(i,n){
		scanf("%lld %lld",&a[i],&b[i]);
	}
	
	vector<long long> xs(n+1);
	
	{
		vector<long long> d(n);
		rep(i,n){
			xs[0] += b[i];
			d[i] = a[i]-b[i];
		}
		sort(d.rbegin(),d.rend());
		rep(i,n){
			xs[i+1] = xs[i] + d[i];
		}
	}
	
	vector<long long> ys(xs.rbegin(),xs.rend());
	//swap(xs,ys);
	int m;
	cin>>m;
	
	vector<int> x(m),y(m);
	rep(i,m){
		scanf("%d %d",&x[i],&y[i]);
	}
	
	vector<long long> ans(m,-1);
	
	map<pair<int,int>,long long> mp;
		
	rep(i,m){
		if(mp.count(make_pair(x[i],y[i]))){
			ans[i] = mp[make_pair(x[i],y[i])];
			printf("%lld\n",ans[i]);
			continue;
		}
		if(x[i] >= y[i]){
			for(int j=0;j<=n;j+=x[i]){
				if((n-j)%y[i]==0){
					ans[i] = max(ans[i],xs[j]);
				}
			}
		}
		else{
			for(int j=0;j<=n;j+=y[i]){
				if((n-j)%x[i]==0){
					ans[i] = max(ans[i],ys[j]);
				}
			}
		}
		mp[make_pair(x[i],y[i])] = ans[i];
		printf("%lld\n",ans[i]);
	}
		
	
	
    return 0;
}