#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	
	int _t;
	cin>>_t;
	rep(_,_t){
		int n,m,k;
		cin>>n>>m>>k;
		
		vector<vector<int>> ans;
		int a,b,c,d;
		a = (n+m-1)/m;
		b = n/m;
		rep(i,1000000){
			long long X = a*i;
			if((n-X)%b==0){
				c = i;
				d = (n-X)/b;
				if(c+d!=m)continue;
				break;
			}
		}
		
		int last = 0;
		rep(i,k){
			int cur = last;
			rep(j,c){
				vector<int> t;
				rep(l,a){
					t.push_back(cur);
					cur ++;
					cur %= n;
				}
				ans.push_back(t);
			}
			last = cur;
			rep(j,d){
				vector<int> t;
				rep(l,b){
					t.push_back(cur);
					cur ++;
					cur %= n;
				}
				ans.push_back(t);
			}
		}
		
		rep(i,ans.size()){
			printf("%d",ans[i].size());
			rep(j,ans[i].size()){
				printf(" %d",ans[i][j]+1);
			}
			printf("\n");
		}
		
	}
	return 0;
}