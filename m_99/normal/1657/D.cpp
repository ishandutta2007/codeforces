#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int n,C;
	cin>>n>>C;
	vector<long long> M(C+1,0);
	
	//vector<pair<long long,long long>> t(n);
	rep(i,n){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		M[a] = max(M[a],b*c);
	}
	for(int i=1;i<=C;i++){
		for(int j=i;j<=C;j+=i){
			M[j] = max(M[j],M[i]*(j/i));
		}
	}
	rep(i,C){
		M[i+1] = max(M[i+1],M[i]);
	}
	
	int m;
	cin>>m;
	vector<long long> ans(m);
	rep(i,m){
		long long a,b;
		scanf("%lld %lld",&a,&b);
		int d = distance(M.begin(),upper_bound(M.begin(),M.end(),a*b));
		if(d==C+1)ans[i] = -1;
		else ans[i] = d;
	}
	rep(i,m){
		if(i!=0)printf(" ");
		printf("%lld",ans[i]);
	}
	cout<<endl;
	
	return 0;
}