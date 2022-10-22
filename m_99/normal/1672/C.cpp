#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		int m = Inf,M = -Inf;
		rep(i,n-1){
			if(a[i]==a[i+1]){
				m = min(m,i+1);
				M = max(M,i);
			}
		}
		int ans = 0;
		if(M-m < 0){
		}
		else{
			ans = max(1,M-m);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}