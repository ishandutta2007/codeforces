#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,l;
int f(int x){
	return x<0?0:(x+1)*(x+2)/2;
}
int calc(int x,int y,int z,int k){
	int res=0;
	for(int i=0;i<=l;i++)
		res+=f(min(k-i,i+x-y-z));
	return res;
}
signed main(){
	cin>>a>>b>>c>>l;
	cout<<calc(0,0,0,2*l)-calc(a,b,c,l)-calc(b,c,a,l)-calc(c,a,b,l)<<"\n";
}