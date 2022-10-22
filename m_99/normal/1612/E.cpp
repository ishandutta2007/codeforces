#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int n;
	cin>>n;
	
	vector<int> m(n),k(n);
	rep(i,n)scanf("%d %d",&m[i],&k[i]);
	
	vector<long long> ans(21,0);
	vector<vector<int>> inds(21);
	
	for(int i=1;i<=20;i++){
		if(n<i)break;
		
		vector<pair<long long,int>> sum(200005);
		rep(j,sum.size()){
			sum[j].first = 0;
			sum[j].second = j;
		}
		
		rep(j,n){
			sum[m[j]].first += min(k[j],i);
		}
		sort(sum.rbegin(),sum.rend());
		rep(j,i){
			ans[i] += sum[j].first;
			inds[i].push_back(sum[j].second);
		}
	}
	
	int Ans= 1;
	for(int i=2;i<=20;i++){
		if(ans[Ans]*i < ans[i]*Ans){
			Ans = i;
		}
	}
	cout<<Ans<<endl;
	rep(i,Ans){
		if(i!=0)cout<<' ';
		cout<<inds[Ans][i];
	}
	cout<<endl;
	
	return 0;
}