#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n)a[i] = i+1;
		
		for(int i=n-3;i>=0;i-=2){
			if(i==2)break;
			swap(a[i],a[i-1]);
		}
		
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
		
		
	}
	
    return 0;
}