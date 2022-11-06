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
	ll x,h,m; cin>>x>>h>>m;
	ll res=0;
	while(h%10!=7&&m%10!=7){
		res++;
		m-=x;
		if(m<0){
			m+=60;
			h=(h-1+24)%24;
		}
	}
	cout<<res;
	
	return 0;
}