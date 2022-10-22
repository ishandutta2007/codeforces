#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		
		vector<int> b = a;
		sort(b.begin(),b.end());
		
		vector<bool> ok(n-1,false);
		rep(i,m){
			int p;
			cin>>p;
			ok[p-1] = true;
		}
		
		rep(i,n){
			int x = 1;
			for(int j=i+1;j<n;j++){
				if(ok[j-1]==false)break;
				x++;
			}
			sort(a.begin()+i,a.begin()+i+x);
		}
		if(a==b)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}