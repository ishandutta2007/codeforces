#include<bits/stdc++.h>
#define double long double
using namespace std;
int n,xl,xr,yl,yr;
double l=0,r=1e6;
void upd(int p,int v,int pl,int pr){
	if(!v){
		if(pl<p&&p<pr)return;
		cout<<"-1\n",exit(0);
	}
	if(v<0)swap(pl,pr);
	l=max(l,1.0l*(pl-p)/v),r=min(r,1.0l*(pr-p)/v);
	if(r<l+1e-11)cout<<"-1\n",exit(0);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>xl>>yl>>xr>>yr;
	for(int i=1;i<=n;i++){
		int x,y,vx,vy;cin>>x>>y>>vx>>vy;
		upd(x,vx,xl,xr),upd(y,vy,yl,yr);
	}
	cout<<fixed<<setprecision(8)<<l<<"\n";
}