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
		cin>>n>>m;
		
		vector<array<long long,3>> A(m);
		rep(i,m){
			long long a,b;
			scanf("%lld %lld",&a,&b);
			A[i][1] = a;
			A[i][0] = b;
			A[i][2] = i;
		}
		sort(A.begin(),A.end());
		
		deque<pair<int,int>> P;
		long long ans=  0LL;
		rep(i,n*2){
			P.emplace_back(A[i][1],A[i][2]);
			ans += A[i][0];
		}
		sort(P.begin(),P.end());
		cout<<ans<<endl;
		rep(i,n){
			printf("%d %d\n",P.front().second+1,1+P.back().second);
			P.pop_front();
			P.pop_back();
		}
		
	}
	
	return 0;
}