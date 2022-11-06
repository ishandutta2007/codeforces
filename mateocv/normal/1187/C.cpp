#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<pair<ll,ll>> v[2];
	fore(i,0,m){
		ll t; cin>>t;
		ll l,r; cin>>l>>r;
		v[t].pb({l,r});
	}
	sort(ALL(v[1]));
	vector<pair<ll,ll>> reg;
	reg.pb({0,0});
	fore(i,0,SZ(v[1])){
		if(v[1][i].fst>reg.back().snd){
			reg.pb(v[1][i]);
		}else{
			reg[SZ(reg)-1].snd=max(reg[SZ(reg)-1].snd,v[1][i].snd);
		}
	}
	/*fore(i,0,SZ(reg)){
		cout<<reg[i].fst<<" "<<reg[i].snd<<"\n";	
	}*/
	ll res[n];
	/*ll com=n;
	fore(i,1,SZ(reg)){
		for(int j=com;j>=com+reg[i].snd-reg[i].fst;j--){
			res.pb(j); cout<<j<<" ";
		}
		cout<<com<<"\n";
		com-=com+1-(com+reg[i].snd-reg[i].fst);
	}*/
	fore(i,1,n+1){
		res[i-1]=(n+1-i);
	}
	fore(i,1,SZ(reg)){
		//auto it=res.begin(),itt=res.begin();
		//fore(j,0,reg[i].fst-1)it++;
		//fore(j,0,reg[i].snd)itt++;
		//swap(res.begin()+reg[i].fst-1,res.begin()+reg[i].snd);
		reverse(res+reg[i].fst-1,res+reg[i].snd);
		//cout<<reg[i].fst-1<<" "<<reg[i].snd<<"\n";
	}
	fore(i,0,SZ(v[0])){
		fore(j,0,SZ(reg)){
			if(v[0][i].fst>=reg[j].fst&&v[0][i].snd<=reg[j].snd){
				cout<<"NO"; return 0;
			}
		}
	}
	cout<<"YES\n";
	fore(i,0,n)cout<<res[i]<<" ";
	return 0;
}