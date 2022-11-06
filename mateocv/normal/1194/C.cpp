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
		string s,t,p; cin>>s>>t>>p;
		ll l=0,r=0,tot=0;
		vector<char> v;
		while(l<SZ(s)&&r<SZ(t)){
			if(s[l]==t[r]){
				tot++; l++; r++;
			}else{
				v.pb(t[r]); r++;
			}
		}
		while(r<SZ(t))v.pb(t[r]),r++;
		if(tot!=SZ(s)){
			cout<<"NO\n";
		}else{
			sort(ALL(v));
			sort(ALL(p));
			//fore(i,0,SZ(v))cout<<v[i]; cout<<"\n";
			//cout<<p<<"\n";
			l=0,r=0,tot=0;
			while(l<SZ(v)&&r<SZ(p)){
				if(v[l]==p[r]){
					tot++; l++; r++;
				}else{
					r++;
				}
			}
			if(tot!=SZ(v))cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
	
	return 0;
}