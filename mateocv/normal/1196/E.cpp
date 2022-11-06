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
	ll q; cin>>q;
	while(q--){
		ll b,w; cin>>b>>w;
		vector<pair<ll,ll>> resb,resw;
		fore(i,0,min(b,w)){
			resw.pb({2,2+2*i});
			resb.pb({2,3+2*i});
		}
		if(b>w){
			ll tot=b-w;
			fore(i,0,min(b,w)){
				if(tot)resb.pb({1,2+2*i}), tot--;
			}
			fore(i,0,min(b,w)){
				if(tot)resb.pb({3,2+2*i}), tot--;
			}
			if(tot)resb.pb({2,1}), tot--;
		}else if(w>b){
			ll tot=w-b;
			fore(i,0,min(b,w)){
				if(tot)resw.pb({1,3+2*i}), tot--;
			}
			fore(i,0,min(b,w)){
				if(tot)resw.pb({3,3+2*i}), tot--;
			}
			if(tot)resw.pb({2,2+2*(min(b,w))}), tot--;
		}
		if(SZ(resb)<b||SZ(resw)<w){
			cout<<"NO\n";
		}else{
			cout<<"YES\n";
			fore(i,0,SZ(resw))cout<<resw[i].fst<<" "<<resw[i].snd<<"\n";
			fore(i,0,SZ(resb))cout<<resb[i].fst<<" "<<resb[i].snd<<"\n";
		}
	}	
	
	return 0;
}