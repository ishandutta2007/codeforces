#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		int ii = 0;
		rep(i,n){
			if(a[ii] < a[i])ii = i;
		}
		cout<<ii+1<<endl;
		
		
	}
	
    return 0;
}