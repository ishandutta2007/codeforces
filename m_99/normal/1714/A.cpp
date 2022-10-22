#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int get(int a,int b,int c,int d){
	int ret = 0;
	while(a!=c||b!=d){
		ret++;
		b++;
		if(b==60){
			b = 0;
			a++;
		}
		a %= 24;
	}
	return ret;
}

int main() {
   
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		int H,M;
		cin>>H>>M;
		
		int ans = Inf;
		
		rep(i,n){
			int h,m;
			cin>>h>>m;
			ans = min(ans,get(H,M,h,m));
		}
		cout<<ans/60<<' '<<ans%60<<endl;
		
		
	}
	
    return 0;
}