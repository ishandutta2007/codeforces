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
		
		int nn = n/2;
		if(nn%2==1){
			cout<<"NO"<<endl;
			continue;
		}
		
		vector<int> x(nn),y(nn);
		rep(i,nn){
			x[i] = i*2+2;
			y[i] = i*2+1;
		}
		y.back() += nn;
		cout<<"YES"<<endl;
		rep(i,nn){
			if(i!=0)cout<<' ';
			cout<<x[i];
		}
		rep(i,nn){
			cout<<' '<<y[i];
		}
		cout<<endl;		
		
	}
	
	return 0;
}