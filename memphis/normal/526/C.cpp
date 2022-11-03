#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define LL long long
#define N 5005

LL c,hr,hb,wr,wb;
LL ans;

LL work(LL l,LL r){
	LL ans=0;
	rep(i,l,r){
		ans=max(ans,i*hr+(c-i*wr)/wb*hb);
	}
	return ans;
}

int main(){
	cin>>c>>hr>>hb>>wr>>wb;
	if(wr<wb) swap(hr,hb),swap(wr,wb);
	if(hb>hr){
		cout<<c/wb*hb<<endl;
		return 0;
	}
	LL top=c/wr;
	if(top<=1000000){
		cout<<work(0,top)<<endl;
		return 0;
	}
	cout<<max(work(0,100000),work(top-100000,top))<<endl;
}