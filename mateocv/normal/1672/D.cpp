#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=200005;

ll oc[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		fore(i,0,n)a[i]--,b[i]--;
		fore(i,0,n)oc[i]=0;
		ll s=0;
		ll br=0,ul=-1,l=0,r=0;
		while(r<n){
			//cout<<l<<" "<<r<<endl;
			if(l<n&&a[l]==b[r]){
				ul=a[l];
				l++; r++;
			}else if(ul==b[r]&&oc[b[r]]){
				oc[b[r]]--;
				s--;
				r++;
			}else if(l<n){
				oc[a[l]]++;
				s++;
				l++;
			}else{
				br++; break;
			}
		}
		//cout<<"f "<<s<<" "<<br<<"\n";
		if(s==0&&!br)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}