#include <bits/stdc++.h>
using namespace std;
#define modulo 100000
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<int> x(n);
	
	set<int> used;
	
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
		used.insert(x[i]);
	}
	
	vector<vector<int>> D(2*m,vector<int>());
	
	int now = 1;
	
	while(used.size()<n+m){
		vector<int> new_x;
		for(int i=0;i<x.size();i++){
			bool f = false;
			if(!used.count(x[i]+now)){
				used.insert(x[i]+now);
				D[now].push_back(x[i]+now);
				f=true;
			}
			if(!used.count(x[i]-now)){
				used.insert(x[i]-now);
				D[now].push_back(x[i]-now);
				f=true;
			}
			if(f){
				new_x.push_back(x[i]);
			}
		}
		swap(x,new_x);
		now++;
	}
	
	vector<int> y;
	long long ans = 0;
	
	for(int i=1;true;i++){
		for(int j=0;j<D[i].size();j++){
			y.push_back(D[i][j]);
			ans += (long long)i;
			if(y.size()==m)break;
		}
		if(y.size()==m)break;
	}
	
	cout<<ans<<endl;
	for(int i=0;i<m;i++){
		if(i!=0)printf(" ");
		printf("%d",y[i]);
	}
	cout<<endl;
	
	
    return 0;
}