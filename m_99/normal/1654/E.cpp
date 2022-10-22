#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	
	int ans = 1;
	auto b = a;
	rep(i,301){
		auto c = b;
		sort(c.begin(),c.end());
		int ss = 0;
		rep(j,c.size()){
			if(j==0 || c[j]!=c[j-1])ss = 1;
			else ss++;
			ans = max(ans,ss);
		}
		rep(j,n){
			b[j] -= j;
		}
	}
	b = a;
	rep(i,301){
		auto c = b;
		sort(c.begin(),c.end());
		int ss = 0;
		rep(j,c.size()){
			if(j==0 || c[j]!=c[j-1])ss = 1;
			else ss++;
			ans = max(ans,ss);
		}
		rep(j,n){
			b[j] += j;
		}
	}
	
	rep(i,n){
		vector<int> ds;
		for(int j=i+1;j<min(n,i+400);j++){
			if((a[j]-a[i])%(j-i)==0)ds.push_back((a[j]-a[i])/(j-i));
		}
		sort(ds.begin(),ds.end());
		int ss = 0;
		rep(j,ds.size()){
			if(j==0 || ds[j]!=ds[j-1])ss = 1;
			else ss++;
			ans = max(ans,ss+1);
		}
	}
	
	cout<<n-ans<<endl;
	
	return 0;
}