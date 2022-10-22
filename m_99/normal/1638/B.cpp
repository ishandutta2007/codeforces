#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<vector<int>> a(2);
		rep(i,n){
			int t;
			scanf("%d",&t);
			a[t%2].push_back(t);
		}
		auto b = a;
		rep(i,2)sort(b[i].begin(),b[i].end());
		if(a==b)printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}