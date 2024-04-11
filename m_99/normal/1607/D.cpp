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
		rep(i,n)scanf("%d",&a[i]);
		string s;
		cin>>s;
		
		vector<int> R,B;
		rep(i,n){
			if(s[i]=='R')R.push_back(a[i]);
			else B.push_back(a[i]);
		}
		
		sort(B.begin(),B.end());
		bool f = true;
		rep(i,B.size()){
			if(B[i]<=i)f = false;
		}
		sort(R.rbegin(),R.rend());
		rep(i,R.size()){
			if(R[i]>=n+1-i)f = false;
		}
		cout<<(f?"YES":"NO")<<endl;
		
	}
	
	return 0;
	
}