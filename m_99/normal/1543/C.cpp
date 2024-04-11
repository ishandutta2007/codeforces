#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

double ans;

void dfs(double c,double m,double p,double v,double cur,double num){
	if(cur < 1e-15)return;
	ans += num * (cur * p);
	
	double t = min(v,c);
	if(m<1e-7)dfs(c-t,m,p+t,v,cur*c,num+1.0);
	else dfs(c-t,m+t/2.0,p+t/2.0,v,cur*c,num+1.0);
	
	t = min(v,m);
	if(c<1e-7)dfs(c,m-t,p+t,v,cur*m,num+1.0);
	else dfs(c+t/2.0,m-t,p+t/2.0,v,cur*m,num+1.0);
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		double c,m,p,v;
		cin>>c>>m>>p>>v;
		ans = 0.0;
		
		dfs(c,m,p,v,1.0,1.0);
		
		cout<<fixed<<setprecision(10)<<ans<<endl;
		
	}
	
    return 0;
}