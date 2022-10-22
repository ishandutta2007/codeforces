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
		scanf("%d",&n);
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		sort(a.begin(),a.end());
		vector<int> x,y;
		rep(i,n){
			if(i==0)continue;
			x.push_back(a[i]);
			y.push_back(a[0]);
		}
		while(x.size()!=n/2){
			x.pop_back();
			y.pop_back();
		}
		
		rep(i,x.size()){
			printf("%d %d\n",x[i],y[i]);
		}
		
	}
	
	
	return 0;
}