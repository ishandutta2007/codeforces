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
	ll n,m; cin>>n>>m;
	pair<ll,ll> a[m];
	fore(i,0,m)cin>>a[i].fst,a[i].snd=i;
	//sort(a,a+m);
	ll sum=0;
	fore(i,0,m)sum+=a[i].fst;
	ll sob=sum-n;
	if(sum>=n){
		ll res[m];
		res[0]=0;
		ll va=a[0].fst-1;
		fore(i,1,m){
			res[i]=res[i-1]+1+va-min(sob,va);
			sob-=min(sob,va);
			va=a[i].fst-1;
		}
		fore(i,0,m){
			if(res[i]+a[i].fst>n){
				cout<<-1; return 0;
			}
		}
		fore(i,0,m)cout<<res[i]+1<<" ";
	}else{
		cout<<-1;
	}
	
	return 0;
}