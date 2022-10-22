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
		
		vector<int> a(n);
		rep(i,n){
			cin>>a[i];
		}
		
		sort(a.begin(),a.end());
		vector<int> b;
		rep(i,n){
			auto it = lower_bound(a.begin(),a.end(),i);
			if(it==a.end() || (*it)!=i)break;
			b.push_back(i);
			a.erase(it);
		}
		rep(i,a.size())b.push_back(a[i]);
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",b[i]);
		}
		printf("\n");
		
		
		
	}
	
    return 0;
}