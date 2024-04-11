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
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		int m;
		{
			vector<int> b = a;
			sort(b.begin(),b.end());
			b.erase(unique(b.begin(),b.end()),b.end());
			m = b.size();
			rep(i,n){
				a[i] = distance(b.begin(),lower_bound(b.begin(),b.end(),a[i]));
			}
		}
		
		vector<vector<int>> inds(m);
		rep(i,n)inds[a[i]].push_back(i);
		
		vector<int> maxi(m,1);
		rep(i,m){
			if(i==0)continue;
			if(inds[i][0] > inds[i-1].back())maxi[i] += maxi[i-1];
		}
		m = 0;
		rep(i,maxi.size())m = max(m,maxi[i]);
		printf("%d\n",maxi.size() - m);
		
		
	}
	
    return 0;
}