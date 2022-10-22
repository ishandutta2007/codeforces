#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf (long long)1000000000000000




int main(){
	
	int q;
	cin>>q;
	
	rep(_,q){
		int n;
		cin>>n;
		
		vector<int> a(n*4);
		rep(i,n*4)cin>>a[i];
		
		sort(a.begin(),a.end());
		
		vector<int> b;
		bool f = true;
		rep(i,2*n){
			if(a[i*2]!=a[i*2+1]){
				f=false;
				break;
			}
			b.push_back(a[i*2]);
		}
		
		if(f){
			rep(i,n-1){
				int X = b[i] * b[n*2-1-i];
				int Y = b[i+1] * b[n*2-2-i];
				if(X!=Y){
					f=false;
					break;
				}
			}
		}
		
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
		
	}
	
	return 0;
}