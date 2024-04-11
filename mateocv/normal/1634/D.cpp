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

map<vector<ll>,ll> mp;

ll cont=0;

ll ask(ll a, ll b, ll c){
	vector<ll> v={a,b,c};
	sort(ALL(v));
	if(mp.count(v))return mp[v];
	cont--;
	assert(cont>=0);
	cout<<"? "<<a+1<<" "<<b+1<<" "<<c+1<<endl;
	ll resp; cin>>resp;
	mp[v]=resp;
	assert(resp!=-1);
	return resp;
}

void answer(ll a, ll b){
	cout<<"! "<<a+1<<" "<<b+1<<endl;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		mp.clear();
		cont=2*n-2;
		if(n==4){
			vector<pair<ll,ll>> resp;
			fore(i,0,4)resp.pb({ask(i,(i+1)%4,(i+2)%4),i});
			sort(ALL(resp));
			ll c[4]={0,0,0,0};
			for(auto i:resp){
				if(i.fst==resp.back().fst){
					fore(j,0,3)c[(i.snd+j)%4]++;
				}
			}
			vector<pair<ll,ll>> oc;
			fore(i,0,4)oc.pb({c[i],i});
			sort(ALL(oc));
			answer(oc[2].snd,oc[3].snd);
		}else{
			vector<pair<ll,ll>> resp;
			fore(i,2,n)resp.pb({ask(0,1,i),i});
			sort(ALL(resp));
			ll pos=resp.back().snd;
			if(resp[0].fst==resp.back().fst){
				ll a=ask(2,3,4);
				pos=2;
				if(a==0){
					ll b=ask(0,2,3),c=ask(1,2,3);
					if(b+c==resp[0].fst){
						answer(0,1);
						continue;
					}
				}else if(a<=resp[0].fst){
					answer(0,1);
					continue;
				}
			}
			vector<ll> v;
			fore(i,0,n){
				if(i!=pos)v.pb(i);
			}
			resp.clear();
			fore(i,0,SZ(v))resp.pb({ask(pos,v[i],v[(i+1)%SZ(v)]),i});
			sort(ALL(resp));
			reverse(ALL(resp));
			ll ot=(resp[0].snd-1==resp[1].snd?v[resp[0].snd]:v[resp[1].snd]);
			answer(pos,ot);
		}
	}
	
	return 0;
}