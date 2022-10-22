#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
int sz = 500;
int Add[500][500];
int imos[200005];
int ans[200005];

int main(){
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	vector<int> x(n),y(n);
	rep(i,n)scanf("%d %d",&x[i],&y[i]);
	
	vector<int> last(n,-1);
	
	rep(i,m){
		int t,k;
		scanf("%d %d",&t,&k);
		k--;
		
		if(t==1){
			if(x[k]+y[k]<sz){
				for(int j=x[k];j<x[k]+y[k];j++){
					Add[x[k]+y[k]][(i+j)%(x[k]+y[k])]++;
				}
			}
			else{
				for(int j=i;j<m;j+=x[k]+y[k]){
					if(j+x[k]<m)imos[j+x[k]]++;
					if(j+x[k]+y[k]<m)imos[j+x[k]+y[k]]--;
				}
				
			}
			last[k] = i;
		}
		else{
			if(x[k]+y[k]<sz){
				for(int j=x[k];j<x[k]+y[k];j++){
					Add[x[k]+y[k]][(last[k]+j)%(x[k]+y[k])]--;
				}
			}
			else{
				
				
				for(int j=last[k];j<m;j+=x[k]+y[k]){
					if(j+x[k]>=i&&j+x[k]<m)imos[j+x[k]]--;
					if(j+x[k]+y[k]>=i&&j+x[k]+y[k]<m)imos[j+x[k]+y[k]]++;
					if(j+x[k]<i&&j+x[k]+y[k]>=i)imos[i]--;
					
				}
				
			}
			last[k] = -1;
			
		}
		
		for(int j=1;j<sz;j++){
			ans[i] += Add[j][i%j];
		}
			
		
	}
	rep(i,m-1){
		imos[i+1] += imos[i];
	}
	rep(i,m)ans[i] += imos[i];
	
	rep(i,m){
		printf("%d\n",ans[i]);
	}
	
	
	return 0;
}