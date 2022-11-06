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

vector<ll> gen(ll a, ll b, ll c){
	vector<ll> v={a,b,c,a+b,b+c,c+a,a+b+c};
	sort(ALL(v));
	return v;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		vector<ll> a(7);
		fore(i,0,7)cin>>a[i];
		ll br=0;
		fore(i,0,7){
			fore(j,i+1,7){
				fore(k,j+1,7){
					if(gen(a[i],a[j],a[k])==a){
						cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<"\n";
						br++; break;
					}
				}
				if(br)break;
			}
			if(br)break;
		}
	}
	
	return 0;
}