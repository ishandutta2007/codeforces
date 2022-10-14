#include<bits/stdc++.h>
#define int long long 
using namespace std;
int x[3],y[3],tx[3],ty[3],xm,ym;
vector<array<int,4> >v;
signed main(){
	for(int i=0;i<3;i++)
		cin>>x[i]>>y[i],tx[i]=x[i],ty[i]=y[i];
	sort(tx,tx+3);
	sort(ty,ty+3);
	xm=tx[1],ym=ty[1];
	for(int i=0;i<3;i++){
		if(x[i]!=xm)
			v.push_back({x[i],y[i],xm,y[i]});
		if(y[i]!=ym)
			v.push_back({xm,y[i],xm,ym});
	}
	cout<<v.size()<<"\n";
	for(auto i:v)
		cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<" "<<i[3]<<"\n";
}