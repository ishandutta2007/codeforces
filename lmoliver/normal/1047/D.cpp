#include<bits/stdc++.h>
using namespace std;
#define F(i) for(int i=1;i<=n;i++)
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
typedef long long LL;
LL work(LL x,LL y){
	
	LL q=(LL)x*y;
	if(x>y)swap(x,y);
	LL arr[6]={0,1,2,3,2,1};
	if(x==1)return (y-arr[y%6])/2;
	if(x==2&&y==2)return 0;
	if(x==2&&y==3)return 2;
	if(x==2&&y==7)return 6;
	return q/2;

}
int main(){
	LL n,m;
	cin>>n>>m;
	cout<<work(n,m)*2;
    return 0;
}