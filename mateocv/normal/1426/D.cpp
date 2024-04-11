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

set<ll> st;

int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll sum=0,prev=0;
	st.insert(sum);
	//cout<<sum<<" ";
	ll res=0;
	fore(i,0,n){
		prev=sum;
		sum+=a[i];
		//cout<<sum<<" ";
		if(st.count(sum)){
			st.clear();
			st.insert(prev);
			st.insert(sum);
			res++;
		}else{
			st.insert(sum);
		}
	}
	//cout<<"\n";
	cout<<res<<"\n";
	return 0;
}