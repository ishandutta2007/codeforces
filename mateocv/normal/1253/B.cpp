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

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	set<ll> est;
	set<ll> st;
	ll va=0;
	vector<ll> v;
	fore(i,0,n){
		if(a[i]>0){
			if(st.count(a[i])||est.count(a[i])){
				cout<<-1; return 0;
			}else{
				st.insert(a[i]);
				est.insert(a[i]);
			}
		}else{
			if(st.count(-a[i])){
				st.erase(-a[i]);
			}else{
				cout<<-1; return 0;
			}
		}
		va++;
		if(SZ(st)==0){
			v.pb(va);
			va=0;
			est.clear();
		}
	}
	if(SZ(st)!=0){
		cout<<-1; return 0;
	}
	cout<<SZ(v)<<"\n";
	fore(i,0,SZ(v))cout<<v[i]<<" ";
	
	return 0;
}