#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		sort(a.begin(),a.end());
		bool f = false;
		rep(i,n){
			if(binary_search(a.begin(),a.end(),a[i]-k))f = true;
		}
		if(f)printf("YES\n");
		else printf("NO\n");
		
		
	}
	
	return 0;
}