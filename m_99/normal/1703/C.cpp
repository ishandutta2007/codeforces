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
		rep(i,n){
			int k;
			cin>>k;
			string s;
			cin>>s;
			rep(j,k){
				if(s[j]=='U')a[i]--;
				else a[i]++;
			}
			a[i]%=10;
			if(a[i]<0)a[i]+=10;
		}
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
		
	}
	
    return 0;
}