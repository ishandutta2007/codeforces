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
typedef int ll;

const int MAXN=505;

ll pre[MAXN][MAXN],pos[MAXN][MAXN];

int main(){FIN;
	ll n,l,k; cin>>n>>l>>k;
	vector<ll> d(n),a(n);
	fore(i,0,n)cin>>d[i];
	d.pb(l);
	fore(i,0,n)cin>>a[i];
	for(ll x=n;x>=0;x--){
		fore(y,0,x+1){
			fore(z,0,k+1){
				auto &res=pos[y][z];
				if(x==n)res=0;
				else{
					res=pre[x][z]+(d[x+1]-d[x])*a[x];
					if(z)res=min(res,pre[y][z-1]+(d[x+1]-d[x])*a[y]);
				}
				//cout<<x<<" "<<y<<" "<<z<<" "<<res<<"\n";
			}
		}
		swap(pre,pos);
	}
	cout<<pre[0][k]<<"\n";
	
	return 0;
}