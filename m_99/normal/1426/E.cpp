#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000005

int main(){

	int n;
	cin>>n;
	
	vector<long long> a(3),b(3);
	
	rep(i,3)cin>>a[i];
	rep(i,3)cin>>b[i];
	
	vector<pair<int,int>> P;
	
	rep(i,3){
		rep(j,3){
			P.emplace_back(i,j);
		}
	}
	
	sort(P.begin(),P.end());
	
	long long m = Inf,M = -Inf;
	
	do{
		vector<long long> A=a,B=b;
		long long win = 0LL;
		rep(i,P.size()){
			long long x = min(A[P[i].first],B[P[i].second]);
			A[P[i].first]-=x;
			B[P[i].second]-=x;
			if((P[i].first+1)%3==P[i].second)win += x;
		}
		
		m = min(m,win);
		M = max(M,win);
			
	}
	while(next_permutation(P.begin(),P.end()));
	
	cout<<m<<' '<<M<<endl;
	
	return 0;
}