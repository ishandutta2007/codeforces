#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	int _t;
	cin>>_t;
	rep(_,_t){
		int n,m;
		scanf("%d %d",&n,&m);
		
		vector<long long> x(n);
		rep(i,n)scanf("%lld",&x[i]);
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		
		long long maxi = -1;
		int ind = -1;
		
		rep(i,1<<n){
			
			vector<int> t(n*2+1);
			long long cur = 0LL;
			vector<int> num(m,0);
			rep(j,n){
				if((i>>j)&1){
					cur -= x[j];
					rep(k,m){
						if(s[j][k]=='1')num[k]++;
					}
				}
				else{
					cur += x[j];
					rep(k,m){
						if(s[j][k]=='1')num[k]--;
					}
				}
			}
			rep(j,m){
				t[num[j]+n]++;
			}
			int tt = 1;
			rep(j,t.size()){
				rep(k,t[j]){
					cur += tt * (j-n);
					tt++;
				}
			}
			if(maxi < cur){
				maxi = cur;
				ind = i;
			}
			
		}
		vector<int> ans(m);
		rep(i,1){
			
			vector<vector<int>> t(n*2+1);
			long long cur = 0LL;
			vector<int> num(m,0);
			rep(j,n){
				if((ind>>j)&1){
					cur -= x[j];
					rep(k,m){
						if(s[j][k]=='1')num[k]++;
					}
				}
				else{
					cur += x[j];
					rep(k,m){
						if(s[j][k]=='1')num[k]--;
					}
				}
			}
			rep(j,m){
				t[num[j]+n].push_back(j);
			}
			int tt = 1;
			rep(j,t.size()){
				rep(k,t[j].size()){
					ans[t[j][k]] = tt;
					tt++;
				}
			}
			
		}
		//cout<<maxi<<endl;
		rep(i,m){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}