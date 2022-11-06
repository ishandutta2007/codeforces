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
 
ll van=0;
 
ll ask(ll i, ll j){
	van++;
	assert(van<=4269);
	cout<<"? "<<i+1<<" "<<j+1<<endl;
	ll resp; cin>>resp;
	assert(resp!=-1);
	return resp;
}
 
int main(){FIN;	//4 try (have fun hackers)
	srand(time(NULL));
	ll n; cin>>n;
	//ll per[n];
	//random_shuffle(per,per+n);
	set<ll> st;
	fore(i,0,n)st.insert(i);
	ll comp=2047;
	while(1){
		ll a=rand()%n,b=rand()%n;
		while(a==b)b=rand()%n;
		ll c=ask(a,b);
		if(__builtin_popcount(c)<=6){
			comp=2047-c;
			fore(i,0,n){
				if(i!=a){
					ll d=ask(a,i);
					if(d&comp)st.erase(i);
				}
			}
			break;
		}
	}
	//cout<<comp<<"\n";
	for(ll i=0;i<=10;i++){
		//cout<<"HOLA "<<i<<endl;
		if((1<<i)&comp)continue;
		while(SZ(st)>2){
			comp|=(1<<i);
			vector<ll> v;
			for(auto j:st)v.pb(j);
			ll a=rand()%SZ(v),b=rand()%n;
			while(v[a]==b)b=rand()%n;
			ll c=ask(v[a],b);
			if(((1ll<<i)&c)==0){
				for(auto j:v){
					if(v[a]!=j){
						if(((1ll<<i)&ask(v[a],j)))st.erase(j);
					}
				}
				break;
			}
		}
	}
	assert(SZ(st)==2);
	pair<ll,ll> p;
	p.fst=*st.begin();
	st.erase(p.fst);
	p.snd=*st.begin();
	st.erase(p.snd);
	ll cero=-1,va=0;
	//cout<<p.fst<<" "<<p.snd<<" "<<comp<<"\n";
	while(1){
		ll r=rand()%n;
		while(r==p.fst||r==p.snd)r=rand()%n;
		if(va){
			if((ask(r,p.fst)&(2047-comp))==0){
				cero=p.fst; break;
			}
		}else{
			if((ask(r,p.snd)&(2047-comp))==0){
				cero=p.snd; break;
			}
		}
		va=1-va;
	}
	ll res[n];
	mset(res,0);
	fore(i,0,n)if(i!=cero)res[i]=ask(i,cero);
	cout<<"! ";
	fore(i,0,n)cout<<res[i]<<" ";
	
	return 0;
}