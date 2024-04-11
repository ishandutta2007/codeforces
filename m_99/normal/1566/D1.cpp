#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,m;
		scanf("%d %d",&n,&m);
		
		vector<pair<int,int>> P(m);
		rep(i,m){
			int a;
			scanf("%d",&a);
			P[i] = make_pair(a,-i);
		}
		sort(P.begin(),P.end());
		
		int ans = 0;
		vector<int> ind(m);
		rep(i,P.size()){
			ind[P[i].second*-1] = i;
		}
		
		vector<int> used;
		rep(i,m){
			int pos = ind[i];
			rep(j,used.size()){
				if(pos > used[j])ans++;
			}
			used.push_back(pos);
		}
		
		printf("%d\n",ans);
		
	}
	
	return 0;
}