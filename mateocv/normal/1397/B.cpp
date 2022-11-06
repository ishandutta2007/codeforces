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
	fore(i,0,n){
		cin>>a[i];
	}
	sort(a,a+n);
	ll res=n*1000000000;
	fore(i,1,1000000001){
		//cout<<i<<" ";
		ll d=0,br=0,pt=1;
		fore(j,0,n){
			//cout<<pt<<" ";
			if(pt>(n+1)*1000000000){
				br++; break;
			}
			d+=abs(pt-a[j]);
			pt*=i;
		}
		//cout<<"\n";
		if(br)break;
		res=min(res,d);
	}
	cout<<res<<"\n";
	
	return 0;
}