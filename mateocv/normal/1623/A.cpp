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
	ll t; cin>>t;
	while(t--){
		ll n,m,x,y,xf,yf; cin>>n>>m>>x>>y>>xf>>yf;
		x--; y--; xf--; yf--;
		ll res=0;
		ll dx=1,dy=1;
		while(x!=xf&&y!=yf){
			res++;
			if(x+dx==-1||x+dx==n)dx=-dx;
			if(y+dy==-1||y+dy==m)dy=-dy;
			x+=dx;
			y+=dy;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}