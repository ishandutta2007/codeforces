#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		bool f = true;
		rep(i,2){
			for(int j=2+i;j<n;j+=2){
				if(a[i]%2 != a[j]%2){
					f = false;
				}
			}
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	
    return 0;
}