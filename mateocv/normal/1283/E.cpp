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
	sort(a,a+n);
	set<ll> st;
	fore(i,0,n){
		if(st.count(a[i]-1)||st.count(a[i])||st.count(a[i]+1))continue;
		st.insert(a[i]+1);
	}
	cout<<SZ(st)<<" ";
	ll ult=a[0]-1,res=1;
	fore(i,1,n){
		if(a[i]-1>ult){
			ult=a[i]-1; res++;
		}else if(a[i]>ult){
			ult=a[i]; res++;
		}else if(a[i]+1>ult){
			ult=a[i]+1; res++;
		}
	}
	cout<<res;
	return 0;
}