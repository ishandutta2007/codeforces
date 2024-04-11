#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll pw(ll a, int e){
	if(!e)return 1;
	if(e%2)return (a*pw(a,e-1))%MOD;
	ll m=pw(a,e/2);
	return (m*m)%MOD;
}

ll fact[200005];
ll comb(int n, int k){
	if(k>n)return 0;
	return (fact[n]*pw((fact[k]*fact[n-k])%MOD,MOD-2))%MOD;
}

int n,k;
vector<pair<int,int> > e;

int main(){
	fact[0]=1;
	fore(i,1,200001)fact[i]=(fact[i-1]*i)%MOD;
	scanf("%d%d",&n,&k);
	fore(i,0,n){
		int l,r;
		scanf("%d%d",&l,&r);
		e.pb(mp(l,-1));
		e.pb(mp(r+1,1));
	}
	sort(e.begin(),e.end());
	int q=0,s=-(1<<30);
	ll r=0;
	fore(i,0,e.size()){
		r+=((e[i].fst-s)*comb(q,k))%MOD;r%=MOD;
		q-=e[i].snd;
		s=e[i].fst;
	}
	cout<<r<<endl;
	return 0;
}