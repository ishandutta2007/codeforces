#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,d; cin>>n>>d;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll res=0;
	map<ll,ll> m;
	fore(i,0,n){
		ll cue=0;
		ll hot=a[i]-d;
		if(!m.count(hot)){
			m[hot]=1;
			fore(j,0,n){
				if(abs(hot-a[j])>=d){
					cue++;
				}	
			}
			if(cue==n)res++;
		}
		cue=0;
		hot=a[i]+d;
		if(!m.count(hot)){
			m[hot]=1;
			fore(j,0,n){
				if(abs(hot-a[j])>=d){
					cue++;
				}	
			}
			if(cue==n)res++;	
		}
		
	}
	cout<<res;
	
	return 0;
}