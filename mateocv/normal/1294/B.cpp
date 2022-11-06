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

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.fst+a.snd<b.fst+b.snd;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		pair<ll,ll> a[n];
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		ll br=0;
		fore(i,0,n){
			fore(j,i+1,n){
				if(a[i].fst+a[i].snd==a[j].fst+a[j].snd){
					cout<<"NO\n"; br++; break;
				}
			}
			if(br)break;
		}
		if(br)continue;
		sort(a,a+n,comp);
		br=0;
		fore(i,0,n){
			fore(j,i+1,n){
				if(a[i].fst>a[j].fst||a[i].snd>a[j].snd){
					//cout<<i<<" "<<j<<"\n";
					cout<<"NO\n"; br++; break;
				}
			}
			if(br)break;
		}
		if(br)continue;
		//sort(a,a+n,comp);
		string res;
		ll sx=0,sy=0;
		fore(i,0,n){
			fore(j,0,a[i].fst-sx)res+='R';
			fore(j,0,a[i].snd-sy)res+='U';
			sx=a[i].fst; sy=a[i].snd;
		}
		cout<<"YES\n"<<res<<"\n";
	}
	
	return 0;
}