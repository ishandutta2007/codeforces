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
		
		vector<int> a(n),b(n);
		rep(i,n)cin>>a[i];
		rep(i,n)cin>>b[i];
		
		bool f = true;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		rep(i,n){
			if(a[i]==b[i]||a[i]+1==b[i])continue;
			f = false;
		}
		cout<<(f?"YES":"NO")<<endl;
		
		
	}
	
	return 0;
}