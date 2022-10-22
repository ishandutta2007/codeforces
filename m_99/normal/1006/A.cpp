#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){

	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	
	rep(i,n){
		if(a[i]%2==0)a[i]--;
	}
	
	rep(i,n){
		if(i!=0)cout<<' ';
		cout<<a[i];
	}
	cout<<endl;
	
	return 0;
}