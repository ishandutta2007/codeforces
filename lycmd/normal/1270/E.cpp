#include<bits/stdc++.h>
using namespace std;
int const N=2333;
int n,x[N],y[N],cntb,cntw;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i],(x[i]+y[i]&1?cntb:cntw)++;
	while(!cntb||!cntw){
		if(!cntb)
			for(int i=1;i<=n;i++)
				x[i]--;
		cntb=cntw=0;
		for(int i=1;i<=n;i++)
			x[i]=x[i]+y[i]>>1,y[i]=x[i]-y[i],
			(x[i]+y[i]&1?cntb:cntw)++;
	}
	cout<<cntb<<"\n";
	for(int i=1;i<=n;i++)
		if(x[i]+y[i]&1)cout<<i<<" ";
}