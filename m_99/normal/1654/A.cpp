#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		sort(a.rbegin(),a.rend());
		cout<<a[0]+a[1]<<endl;
		
		
		
	}
	
	return 0;
}