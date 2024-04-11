#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 2000000000


int main(){	

	int t;
	cin>>t;
	
	rep(_,t){
		int n;
		cin>>n;
		
		vector<int> a;
		int sum = 0;
		int c = 0;
		rep(i,n){
			int t;
			cin>>t;
			if(t!=0)a.push_back(t);
			else c ++;
			sum += t;
		}
		
		if(sum==0){
			cout<<"NO"<<endl;
			continue;
		}
		if(sum>0){
			sort(a.rbegin(),a.rend());
		}
		else{
			sort(a.begin(),a.end());
		}
		rep(i,c)a.push_back(0);
		
		cout<<"YES"<<endl;
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<a[i];
		}
		cout<<endl;
	}
	
    return 0;
}