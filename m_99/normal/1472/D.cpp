#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

long long solve(int N,vector<long long> a,vector<long long> b){

	vector<pair<int,pair<int,int>>> vec;

	
	for(int i=0;i<N;i++){
		vec.emplace_back(a[i]+b[i],make_pair(a[i],b[i]));
	}
	long long A=0;
	long long B=0;
	sort(vec.begin(),vec.end(),greater<pair<int,pair<int,int>>>());
	
	for(int i=0;i<N;i++){
		if(i%2==0){
			A+=vec[i].second.first;
		}
		else{
			B+=vec[i].second.second;
		}
	}return A-B;//cout<<A-B<<endl;
	
	
	return 0;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);

		vector<long long> a(n,0),b(n,0);
		rep(i,n){
			long long t;
			scanf("%lld",&t);
			if(t%2==1)b[i] = t;
			else a[i] = t;
		}
		long long ans = solve(n,a,b);
	
		if(ans==0)printf("Tie\n");
		else if(ans>0)printf("Alice\n");
		else printf("Bob\n");
		
		
	}
	
    return 0;
}