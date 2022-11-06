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

ll n;

vector<ll> oc[100005];

vector<ll> gen(vector<pair<ll,ll>> a, vector<pair<ll,ll>> b){
	//cout<<"gen\n";
	//cout<<"a\n"; for(auto i:a)cout<<i.fst<<" "<<i.snd<<"\n";
	//cout<<"b\n"; for(auto i:b)cout<<i.fst<<" "<<i.snd<<"\n";
	vector<ll> res(n,-1);
	for(auto i:b)res[i.fst]=0,res[i.snd]=0;
	fore(i,0,n)oc[i].clear();
	for(auto &i:a)if(i.fst>i.snd)swap(i.fst,i.snd);
	for(auto i:a)oc[i.fst].pb(i.snd);
	fore(i,0,n){
		ll ex=0;
		ll c[2]={0,0};
		for(auto j:oc[i]){
			if(res[j]!=-1)c[res[j]]++;
			ex+=(j==i);
		}
		if(res[i]==0||(res[i]==-1&&c[0]==0&&!ex)){
			res[i]=0;
			for(auto j:oc[i])res[j]=1;
		}else res[i]=1;
	}
	//for(auto i:res)cout<<i<<" "; cout<<"\n";
	return res;
}

int main(){FIN;
	ll q; cin>>n>>q;
	vector<pair<ll,ll>> a(q);
	vector<ll> vx(q);
	fore(i,0,q){
		cin>>a[i].fst>>a[i].snd>>vx[i];
		a[i].fst--;
		a[i].snd--;
	}
	vector<ll> res(n);
	fore(k,0,30){
		vector<pair<ll,ll>> qa,qb;
		fore(i,0,q){
			if((1ll<<k)&vx[i])qa.pb(a[i]);
			else qb.pb(a[i]);
		}
		auto g=gen(qa,qb);
		fore(i,0,n){
			res[i]+=g[i]*(1ll<<k);
		}
	}
	for(auto i:res)cout<<i<<" ";
	cout<<"\n";
	
	return 0;
}