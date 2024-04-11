#include<bits/stdc++.h>
#define int long long
using namespace std;
int const MOD=998244353;
int d,n,x,y;
vector<int>f;
map<int,int>cnt;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int calc(int x){
	if(cnt.count(x))return cnt[x];
	int ans=0,t=x;
	for(int y:f)
		if(x%y==0){
			ans=(ans+calc(t/y))%MOD;
			while(x%y==0)x/=y;
		}
	if(x>1)ans=(ans+calc(t/x))%MOD;
	return cnt[t]=ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>d>>n;
	for(int i=2;i*i<=d;i++)
		if(d%i==0){
			f.push_back(i);
			while(d%i==0)d/=i;
		}
	if(d>1)f.push_back(d);
	cnt[1]=1;
	while(n--)
		cin>>x>>y,cout<<calc(x/gcd(x,y))*calc(y/gcd(x,y))%MOD<<"\n";
}