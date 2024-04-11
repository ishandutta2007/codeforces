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
		int s = 0;
		rep(i,n){
			cin>>a[i];
			s += a[i];
		}
		s = (s+n-1)/n;
		cout<<s<<endl;
		
	}
	
	return 0;
}