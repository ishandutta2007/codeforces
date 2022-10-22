#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000005


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long W,H,x0,x1,y0,y1,w,h;
		cin>>W>>H>>x0>>y0>>x1>>y1>>w>>h;
		
		if((x1-x0)+w>W && (y1-y0)+h>H){
			cout<<-1<<endl;
			continue;
		}
		
		long long ww = max(x0,W-x1),hh = max(y0,H-y1);
		ww = max(0LL,w-ww),hh = max(0LL,h-hh);
		double ans = 1e15;
		if((x1-x0)+w<=W){
			ans = min(ans,(double)ww);
		}
		if((y1-y0)+h<=H){
			ans = min(ans,(double)hh);
		}
		
		cout<<fixed<<setprecision(15)<<ans<<endl;
	}
	
	return 0;
}