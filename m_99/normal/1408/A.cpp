#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300


int main(){	
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n),b(n),c(n);
		
		rep(i,n){
			cin>>a[i];
		}
		rep(i,n){
			cin>>b[i];
		}
		rep(i,n){
			cin>>c[i];
		}
		
		vector<int> p(n);
		
		rep(i,n){
			set<int> S;
			if(i!=0)S.insert(p[i-1]);
			if(i==n-1)S.insert(p[0]);
			
			if(!S.count(a[i]))p[i] = a[i];
			else if(!S.count(b[i]))p[i] = b[i];
			else p[i] = c[i];
		}
		
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<p[i];
		}
		cout<<endl;
		
		
	}
	
    return 0;
}