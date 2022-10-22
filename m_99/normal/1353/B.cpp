#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		vector<int> a(n),b(n);
		rep(i,n)cin>>a[i];
		rep(i,n)cin>>b[i];
		
		rep(i,k){
			int x = 0,y = 0;
			rep(j,n){
				if(a[x]>a[j])x = j;
			}
			rep(j,n){
				if(b[y]<b[j])y = j;
			}
			if(a[x]<b[y]){
				swap(a[x],b[y]);
			}
		}
		
		int ans = 0;
		rep(i,n)ans += a[i];
		cout<<ans<<endl;
		
	}
	
	return 0;
}