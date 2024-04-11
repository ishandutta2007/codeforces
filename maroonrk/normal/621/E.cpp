#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back

using uint=unsigned int;
using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

const int mod=1000000007;


void Add(int& a,ll b){
	a=(ll(a)+b)%mod;
}

int x;

ll modPow(ll a,ll p){
	ll s=1;
	REP(i,30){
		if((p>>i)&1)
			s=s*a%x;
		a=a*a%x;
	}
	return s;
}

vi kake(const vi& src,ll v){
	vi ret(x,0);
	REP(i,x)
		Add(ret[(i*v)%x],src[i]);
	return ret;
}

vi conv(const vi& a,const vi& b){
	vi ret(x,0);
	REP(i,x)REP(j,x)
		Add(ret[(i+j)%x],ll(a[i])*b[j]);
	return ret;
}

int main(){
	int n=read(),b=read(),k=read();
	x=read();
	vi s(x,0);
	REP(i,n)
		s[read()%x]++;
	vi ans(x,0);
	ans[0]=1;
	REP(i,30){
		if((b>>i)&1)
			ans=conv(kake(ans,modPow(10,(1<<i))),s);
		s=conv(kake(s,modPow(10,(1<<i))),s);
	}
	cout<<ans[k]<<endl;
}