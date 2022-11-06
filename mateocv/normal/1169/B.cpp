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
	ll n,m; cin>>n>>m;
	pair<ll,ll> p[m];
	fore(i,0,m)cin>>p[i].fst>>p[i].snd;
	ll x=-1,y=-1,z=-1;
	x=p[0].fst;
	fore(i,0,m){
		if(p[i].fst!=x&&p[i].snd!=x){
			y=p[i].fst; z=p[i].snd;
			fore(j,i,m){
				if(p[j].fst!=x&&p[j].snd!=x&&p[j].fst!=y&&p[j].snd!=y)break;
				if(j==m-1){
					cout<<"YES"; return 0;
				}
			}
			fore(j,i,m){
				if(p[j].fst!=x&&p[j].snd!=x&&p[j].fst!=z&&p[j].snd!=z)break;
				if(j==m-1){
					cout<<"YES"; return 0;
				}
			}
			break;
		}
		if(i==m-1){
			cout<<"YES"; return 0;
		}
	}
	x=p[0].snd;
	fore(i,0,m){
		if(p[i].fst!=x&&p[i].snd!=x){
			y=p[i].fst; z=p[i].snd;
			fore(j,i,m){
				if(p[j].fst!=x&&p[j].snd!=x&&p[j].fst!=y&&p[j].snd!=y)break;
				if(j==m-1){
					cout<<"YES"; return 0;
				}
			}
			fore(j,i,m){
				if(p[j].fst!=x&&p[j].snd!=x&&p[j].fst!=z&&p[j].snd!=z)break;
				if(j==m-1){
					cout<<"YES"; return 0;
				}
			}
			break;
		}
		if(i==m-1){
			cout<<"YES"; return 0;
		}
	}
	cout<<"NO"; return 0;
	return 0;
}