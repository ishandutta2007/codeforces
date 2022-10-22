#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300000000



int main(){	
	
	int n,t;
	cin>>n>>t;
	vector<int> a(n);
	rep(i,n){
		cin>>a[i];
	}
	
	rep(i,n){
		t -= 86400 - a[i];
		if(t<=0){
			cout<<i+1<<endl;
			return 0;
		}
	}
	
	

    return 0;
}