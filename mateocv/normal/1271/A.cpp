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
	ll a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
	ll res=0;
	while(d){
		if(a==0&&(b==0||c==0))break;
		if((e>f&&a)||b==0||c==0){
			res+=e;
			d--; a--;
		}else{
			res+=f;
			b--; c--; d--;
		}
	}
	cout<<res;
	return 0;
}