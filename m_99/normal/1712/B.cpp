#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main() {
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> p(n);
		rep(i,n)p[i] = i+1;
		for(int i=n-1;i>=1;i-=2){
			swap(p[i],p[i-1]);
		}
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<p[i];
		}
		cout<<endl;
		
	}
	
    return 0;
}