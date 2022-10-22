#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector d(n,vector<long long>(n,Inf64));
		rep(i,n)d[i][i] = 0;
		vector<int> aa,bb,ww;
		rep(i,m){
			int a,b,w;
			scanf("%d %d %d",&a,&b,&w);
			a--,b--;
			d[a][b] = min(d[a][b],1LL);
			d[b][a] = min(d[b][a],1LL);
			aa.push_back(a);
			bb.push_back(b);
			ww.push_back(w);
		}
		
		rep(i,n){
			rep(j,n){
				rep(k,n){
					d[j][k] = min(d[j][k],d[j][i] + d[i][k]);
				}
			}
		}
		
		long long ans = Inf64;
		rep(i,m){
			ans = min(ans,(d[0][aa[i]]+d[bb[i]][n-1]+1)*ww[i]);
			ans = min(ans,(d[0][bb[i]]+d[aa[i]][n-1]+1)*ww[i]);
			
			rep(k,2){
				rep(j,n){
					long long tt = d[0][j] + d[j][n-1];
					
					tt += d[j][aa[i]];
					//if(i==m-1)cout<<tt<<endl;
					tt +=2;
					ans = min(ans,tt*ww[i]);
				}
				swap(aa[i],bb[i]);
				
			}
			
		}
		printf("%lld\n",ans);
	}	
	
	return 0;
}