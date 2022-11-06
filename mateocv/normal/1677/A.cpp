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

const int MAXN=5005;

vector<int> sump[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)a[i]--;
		fore(i,0,n){
			sump[i].clear();
			sump[i].resize(n+1);
			sump[i][0]=0;
			fore(j,0,n)sump[i][j+1]=(sump[i][j]+(a[j]<i));
		}
		ll res=0;
		fore(i,0,n){
			fore(j,i+1,n){
				res+=(sump[a[j]][i]-sump[a[j]][0])*(sump[a[i]][n]-sump[a[i]][j+1]);
			}
		}
		cout<<res<<"\n";
	}
	
	return 0;
}