#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		
		vector cnt(n,vector<int>());
		vector<int> color(n,0);
		rep(i,n){
			int a;
			scanf("%d",&a);
			a--;
			cnt[a].push_back(i);
		}
		
		vector<int> Y;
		rep(i,cnt.size()){
			if(cnt[i].size()>=k){
				rep(j,k){
					color[cnt[i][j]] = j+1;
				}
			}
			else{
				rep(j,cnt[i].size()){
					Y.push_back(cnt[i][j]);
				}
			}
		}
		
		while(Y.size()%k!=0)Y.pop_back();
		
		rep(i,Y.size()){
			color[Y[i]] = (i%k)+1;
		}
		
		rep(i,color.size()){
			if(i!=0)printf(" ");
			printf("%d",color[i]);
		}
		printf("\n");
	}
	
	return 0;
}