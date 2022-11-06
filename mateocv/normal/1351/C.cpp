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

pair<ll,ll> operator+(pair<ll,ll> a, pair<ll,ll> b){
	return {a.fst+b.fst,a.snd+b.snd};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		set<pair<pair<ll,ll>,pair<ll,ll>>> st;
		pair<ll,ll> pos={0,0};
		ll res=0;
		string SNWE="SNWE";
		vector<pair<ll,ll>> d={{0,-1},{0,1},{-1,0},{1,0}};
		fore(i,0,SZ(s)){
			pair<ll,ll> next;
			fore(j,0,4){
				if(s[i]==SNWE[j])next=pos+d[j];
			}
			if(st.count({min(pos,next),max(pos,next)}))res++;
			else{
				st.insert({min(pos,next),max(pos,next)});
				res+=5;
			}
			pos=next;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}