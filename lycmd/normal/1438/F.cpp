#include<bits/stdc++.h>
using namespace std;
int const N=2333333;
int n,p1,p2,cnt[N];
namespace rando{
	mt19937_64 rnd(chrono::steady_clock::
		now().time_since_epoch().count());
	auto gen=[](int l,int r){return rnd()%(r-l+1)+l;};
}
int query(int a,int b,int c){
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	cin>>a;return a;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n,n=(1<<n)-1;
	for(int q=400;q--;){
		int x=rando::gen(1,n),y=rando::gen(1,n),z=rando::gen(1,n);
		while(x==y||x==z||y==z)
			x=rando::gen(1,n),y=rando::gen(1,n),z=rando::gen(1,n);
		cnt[query(x,y,z)]++;
	}
	for(int i=1;i<=n;i++)
		if(cnt[i]>cnt[p1])p2=p1,p1=i;
		else if(cnt[i]>cnt[p2])p2=i;
	for(int i=1;i<=n;i++){
		if(i==p1||i==p2)continue;
		if(query(p1,p2,i)==i)
			cout<<"! "<<i<<endl,exit(0);
	}
}