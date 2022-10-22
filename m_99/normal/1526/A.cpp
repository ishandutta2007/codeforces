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
		
		vector<int> a(2*n);
		rep(i,2*n)cin>>a[i];
		
		sort(a.begin(),a.end());
		
		rep(i,2*n){
			int v;
			if(i%2==0){
				v = a[0];
				a.erase(a.begin());
			}
			else{
				v = a.back();
				a.pop_back();
			}
			if(i!=0)cout<<' ';
			cout<<v;
		}
		cout<<endl;
		
		
		
	}
	
	return 0;
}