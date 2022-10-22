#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	vector<long long> a(6);
	rep(i,6)cin>>a[i];
	
	int n;
	cin>>n;
	
	vector<long long> b(n);
	
	rep(i,n)scanf("%lld",&b[i]);
	
	vector<vector<int>> c(n,vector<int>(6));
	
	vector<int> t;
	rep(i,n){
		rep(j,6){
			t.push_back(b[i]-a[j]);
			c[i][j] = b[i]-a[j];
		}
		sort(c[i].begin(),c[i].end());
	}
	
	sort(t.begin(),t.end());
	t.erase(unique(t.begin(),t.end()),t.end());
	
	vector<vector<int>> inds(t.size(),vector<int>());
	
	rep(i,n){
		rep(j,6){
			int ind = distance(t.begin(),lower_bound(t.begin(),t.end(),c[i][j]));
			inds[ind].push_back(i);
		}
	}
	
	vector<int> cnt(n,0);
	int Cnt = 0;
	
	int ans = Inf+5;
	int r = 0;
	
	rep(i,inds.size()){
		
		while(r!=inds.size()&&Cnt!=n){
			rep(j,inds[r].size()){
				int temp = inds[r][j];
				cnt[temp]++;
				if(cnt[temp]==1)Cnt++;
			}
			r++;
		}
		
		if(Cnt == n){
			ans = min(ans,t[r-1]-t[i]);
		}
		else break;
		
		rep(j,inds[i].size()){
			int temp = inds[i][j];
			cnt[temp]--;
			if(cnt[temp]==0)Cnt--;
		}
		
	}
	
	cout<<ans<<endl;
	
	
    return 0;
}