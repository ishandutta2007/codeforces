#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001



int main() {
	
	int n,q;
	cin>>n>>q;
	vector<int> x(q),y(q),z(q);
	vector<vector<int>> t(n);
	rep(i,q){
		scanf("%d %d %d",&x[i],&y[i],&z[i]);
		x[i]--,y[i]--;
		if(x[i]>y[i])swap(x[i],y[i]);
		t[x[i]].push_back(i);
	}
	
	
	vector<int> ans(n,0);
	rep(i,30){
		vector<int> v(n,-1);
		rep(j,q){
			if(x[j]==y[j]){
				v[x[j]] = (z[j]>>i)&1;
				v[y[j]] = (z[j]>>i)&1;
			}
			else{
				if((z[j]>>i)&1){
				}
				else{
					v[x[j]] = 0;
					v[y[j]] = 0;
				}
			}
		}
		rep(j,n){
			if(v[j]==1)continue;
			bool f = true;
			rep(k,t[j].size()){
				int ii = t[j][k];
				if(x[ii]==y[ii])continue;
				if((z[ii]>>i)&1){
					if(v[y[ii]]==0){
						f = false;
						break;
					}
				}
			}
			if(f){
				rep(k,t[j].size()){
					int ii = t[j][k];
					if(x[ii]==y[ii])continue;
					if((z[ii]>>i)&1){
						v[y[ii]] = 1;
					}
				}
			}
			else v[j] = 1;
		}
		rep(j,n){
			if(v[j]==1)ans[j] |= 1<<i;
		}
	}
	
	rep(i,n){
		if(i!=0)printf(" ");
		printf("%d",ans[i]);
	}
	cout<<endl;
	
    return 0;
}