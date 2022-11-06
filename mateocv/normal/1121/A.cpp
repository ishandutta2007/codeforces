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
	ll n,m,k; cin>>n>>m>>k;
	pair<ll,ll> st[n];
	ll el[k];
	fore(i,0,n)cin>>st[i].fst;
	fore(i,0,n)cin>>st[i].snd;
	fore(i,0,k)cin>>el[i];
	//sort(st,st+n);
	ll maxs[m];
	memset(maxs,0,sizeof maxs);
	fore(i,0,n){
		maxs[st[i].snd-1]=max(maxs[st[i].snd-1],st[i].fst);
	}
	ll res=0;
	fore(i,0,k){
		if(maxs[st[el[i]-1].snd-1]!=st[el[i]-1].fst){
			res++;
		}
	}
	/*fore(i,0,m){
	    cout<<maxs[i]<<" ";
	}
	cout<<"\n"<<res;*/
	cout<<res;
	return 0;
}