#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int query(int c){
	cout<<"+ "<<c<<endl;
	int ret;
	cin>>ret;
	return ret;
}

int answer(int ans){
	cout<<"! "<<ans<<endl;
	exit(0);
}

int main(){
	
	int n;
	cin>>n;
	
	int l = 1,r = n;
	int last = 0;
	while(r-l>1){
		int mid = (r+l)/2;
		mid %= n;
		mid = n-mid;
		if(mid==n)mid--;
		if(mid==0)mid++;
		int ret = query(mid);
		l+=mid;
		r+=mid;
		if(last==ret){
			while(r%n!=0)r--;
		}
		else{
			while(l%n!=0)l++;
		}
		last = ret;
		
	}
	answer(l);
		
	
	return 0;
}