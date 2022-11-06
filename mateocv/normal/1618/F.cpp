#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

string ntob(ll n){
	string s;
	while(n){
		if(n&1)s+='1';
		else s+='0';
		n/=2;
	}
	reverse(ALL(s));
	return s;
}

bool solve(ll x, ll y){
	auto sx=ntob(x),sy=ntob(y);
	ll ex=SZ(sy)-SZ(sx);
	if(ex<0)return 0;
	auto sxr=sx;
	reverse(ALL(sxr));
	fore(i,0,ex+1){
		if(string(i,'1')+sx+string(ex-i,'1')==sy)return 1;
		if(string(i,'1')+sxr+string(ex-i,'1')==sy)return 1;
	}
	return 0;
}

int main(){FIN;
	ll x,y; cin>>x>>y;
	if(x==y){
		cout<<"YES\n";
		return 0;
	}
	ll x0=x;
	while(x0%2==0)x0/=2;
	ll x1=2ll*x+1;
	if(solve(x0,y)||solve(x1,y))cout<<"YES\n";
	else cout<<"NO\n";
	
	return 0;
}