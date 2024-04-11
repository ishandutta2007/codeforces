#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

basic_string<int> RES;

int S(int l,int r){
	return r-l+1;
}

void solve(){
	int n,m;cin>>n>>m;
	string s;cin>>s;
	int c0=count(s.begin(),s.end(),'0'),
		c1=count(s.begin(),s.end(),'1');
	int A=c0,B=c1;
	int g=__gcd(c0,c1);
	c0/=g,c1/=g;
	if(m*c0%(c0+c1)||m*c1%(c0+c1)){
		RES+=-1;
//		cout<<-1<<endl;
		return ;
	}
	int sm=c0+c1;
	c0=m*c0/sm,c1=m*c1/sm;
	int cnt=0,n0=0,n1=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1')n1++;else n0++;
		cnt++;
		if(cnt>m){
			if(s[i-m]=='1')n1--;else n0--;cnt--;
		}
		if(cnt==m){
			if(n0==c0){
				RES+=1;
				RES+=i-m+2;
				RES+=i+1;
				return;
			}
		}
	}
	c0=A-c0,c1=A-c1,m=n-m,cnt=0,n0=0,n1=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1')n1++;else n0++;
		cnt++;
		if(cnt>m){
			if(s[i-m]=='1')n1--;else n0--;cnt--;
		}
		if(cnt==m){
			if(n0==c0){
				RES+=2;
				RES+=1;
				RES+=i-m+1;
				RES+=i+2;
				RES+=n;
				return;
			}
		}
	}
}

main(){
	//freopen("data.txt","r",stdin);
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	for(auto x:RES)cout<<x<<' ';
}