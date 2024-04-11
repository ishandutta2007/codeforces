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
		rep(i,n){
			cin>>a[i];
		}
		
		rep(i,n){
			int ans = 0;
			rep(j,n){
				if(a[i]==a[j])ans++;
			}
			if(ans==1){
				cout<<i+1<<endl;
			}
		}
		
	}
	
	return 0;
}