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

const ll MOD=998244353;

ll fpow(ll b, ll e){
	assert(e>=0);
	ll res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	set<pair<ll,ll>> st[2];
	vector<pair<ll,ll>> c0(n);
	ll cant0[2][2]={{n,0},{0,0}};
	vector<pair<ll,ll>> c1(m);
	ll cant1[2][2]={{m,0},{0,0}};
	while(k--){
		//cout<<k<<":\n"<<endl;
		ll x,y,ty; cin>>x>>y>>ty; x--; y--;
		if(st[0].count({x,y})){
			cant0[!!c0[x].fst][!!c0[x].snd]--;
			if((y)&1)c0[x].fst--;
			else c0[x].snd--;
			cant0[!!c0[x].fst][!!c0[x].snd]++;
			cant1[!!c1[y].fst][!!c1[y].snd]--;
			c1[y].fst--;
			cant1[!!c1[y].fst][!!c1[y].snd]++;
			st[0].erase({x,y});
		}
		if(st[1].count({x,y})){
			cant0[!!c0[x].fst][!!c0[x].snd]--;
			if((y+1)&1)c0[x].fst--;
			else c0[x].snd--;
			cant0[!!c0[x].fst][!!c0[x].snd]++;
			cant1[!!c1[y].fst][!!c1[y].snd]--;
			c1[y].snd--;
			cant1[!!c1[y].fst][!!c1[y].snd]++;
			st[1].erase({x,y});
		}
		//cout<<"HOLAAAAAA"<<endl;
		if(ty!=-1){
			ty^=(x&1);
			if(ty==0){
				cant0[!!c0[x].fst][!!c0[x].snd]--;
				if((y+ty)&1)c0[x].fst++;
				else c0[x].snd++;
				cant0[!!c0[x].fst][!!c0[x].snd]++;
				cant1[!!c1[y].fst][!!c1[y].snd]--;
				c1[y].fst++;
				cant1[!!c1[y].fst][!!c1[y].snd]++;
				st[0].insert({x,y});
			}else{
				cant0[!!c0[x].fst][!!c0[x].snd]--;
				if((y+ty)&1)c0[x].fst++;
				else c0[x].snd++;
				cant0[!!c0[x].fst][!!c0[x].snd]++;
				cant1[!!c1[y].fst][!!c1[y].snd]--;
				c1[y].snd++;
				cant1[!!c1[y].fst][!!c1[y].snd]++;
				st[1].insert({x,y});
			}
		}
		/*
		fore(i,0,2){
			fore(j,0,2){
				cout<<i<<" "<<j<<" "<<cant0[i][j]<<endl;
			}
		}
		fore(i,0,2){
			fore(j,0,2){
				cout<<i<<" "<<j<<" "<<cant1[i][j]<<endl;
			}
		}
		*/
		ll res=0;
		if(!cant0[1][1])res=(res+fpow(2,cant0[0][0]))%MOD;
		if(!cant1[1][1])res=(res+fpow(2,cant1[0][0]))%MOD;
		if(!cant0[1][1])res=(res+MOD-(cant0[0][1]==0)-(cant0[1][0]==0))%MOD;
		cout<<res<<"\n";
	}
	 
	
	return 0;
}