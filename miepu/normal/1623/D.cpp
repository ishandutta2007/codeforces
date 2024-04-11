#include<bits/stdc++.h>
#define int long long
const int N=1000005,mod=1e9+7;
using namespace std;

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

map<vector<int>,int> A;
vector<vector<int>>q;

void solve(){
	A.clear();
	q.clear();
	int n,m,a,b,c,d,na=1,nb=1;cin>>n>>m>>a>>b>>c>>d;
	if(a==1)na=1;
	if(a==n)na=-1;
	if(b==1)nb=1;
	if(b==m)nb=-1;
	int p,cnt=0;cin>>p;p=p*inv(100)%mod;
	while(!A[{a,b,na,nb}]){
		q.push_back({a,b,na,nb});
		A[{a,b,na,nb}]=1;
		a+=na,b+=nb;
		if(a==c||b==d)cnt++;
		if(a==1)na=1;
		if(a==n)na=-1;
		if(b==1)nb=1;
		if(b==m)nb=-1;
		
	}
	int ans=0;
	int t=gsc(1-p,cnt);
	int l=q.size();
	for(int i=0,np=1;i<q.size();i++){
		auto o=q[i];
		if(o[0]==c||o[1]==d){
			ans=ans+p*i%mod*np%mod*inv(1-t)%mod;
			ans=ans+np*l%mod*p%mod*t%mod*inv(1-t)%mod*inv(1-t)%mod; 
			np=np*(1-p+mod)%mod;
		}
	}
	cout<<(ans%mod+mod)%mod<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}