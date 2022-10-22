#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300


int main(){	

	int n;
	cin>>n;
	
	vector<int> a(n);
	int sum = 0;
	
	rep(i,n){
		cin>>a[i];
		sum += a[i];
	}
	
	int s2 = 0;
	
	rep(i,n){
		s2 += a[i];
		if(s2*2>=sum){
			cout<<i+1<<endl;
			return 0;
		}
	}
	
    return 0;
}