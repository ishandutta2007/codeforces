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
		
		vector<deque<int>> D;
		
		rep(i,n){
			int a;
			scanf("%d",&a);
			a--;
			if(D.size()==0 || D.back().back()==a){
				D.push_back(deque<int>(1,a));
			}
			else{
				D.back().push_back(a);
			}
		}
		
		vector<int> NG(n,0);
		rep(i,D.size()){
			if(D[i].front()==D[i].back()){
				NG[D[i].front()]++;
			}
		}
		
		int ans = D.size()-1;
		int M = -1,ind = -1;
		rep(i,n){
			if(M<NG[i]){
				M = NG[i];
				ind = i;
			}
		}
		
		rep(i,D.size()){
			if(D[i].front()!=ind&&D[i].back()!=ind)M--;
		}
		
		rep(i,D.size()){
			if(M<=1)break;
			rep(j,D[i].size()-1){
				if(M<=1)break;
				if(D[i][j]!=ind&&D[i][j+1]!=ind){
					M--;
					ans++;
				}
			}
		}
		
		if(M<=1){
			printf("%d\n",ans);
		}
		else{
			printf("-1\n");
		}
		
	}
	
    return 0;
}