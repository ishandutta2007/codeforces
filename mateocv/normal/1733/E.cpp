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
	ll q; cin>>q;
	while(q--){
		ll t,x,y; cin>>t>>x>>y;
		if(t<x+y){
			cout<<"NO\n";
			continue;
		}
		t-=x+y;
		ll c[120][120],d[120][120];
		mset(c,0);
		mset(d,0);
		c[0][0]=t;
		fore(i,0,120){
			fore(j,0,120){
				if(i+1<120)c[i+1][j]+=c[i][j]/2;
				if(j+1<120)c[i][j+1]+=(c[i][j]+1)/2;
				if(c[i][j]&1)d[i][j]=1;
			}
		}
		ll px=0,py=0;
		fore(i,0,x+y){
			if(d[px][py])px++;
			else py++;
			if(px==120||py==120)break;
		}
		if(px==x&&py==y)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}