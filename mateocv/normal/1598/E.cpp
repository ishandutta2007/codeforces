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

ll n,m;

const int MAXN=2020;

ll t[MAXN][MAXN];

ll t0[MAXN][MAXN];

ll c0[MAXN][MAXN][2];

ll res0=0;

void rec0(ll x){
	pair<ll,ll> pr={-1,-1};
	fore(j,0,MAXN){
		fore(i,x,x+2){
			if(t0[i][j]==1){
				res0-=c0[i][j][i-x];
				c0[i][j][i-x]=0;
			}else{
				res0-=c0[i][j][i-x];
				if(pr.fst!=-1)c0[i][j][i-x]=c0[pr.fst][pr.snd][(i-x)^1]+1;
				else c0[i][j][i-x]=1;
				res0+=c0[i][j][i-x];
			}
			pr={i,j};
		}
	}
}

bool valid(ll x){
	return 0<=x&&x<MAXN-1;
}

void db(ll n){
	cout<<"t:\n";
	fore(i,0,n){
		fore(j,0,n){
			cout<<t[i][j];
		}
		cout<<"\n";
	}
	cout<<"t0:\n";
	fore(i,0,n){
		fore(j,0,n){
			cout<<t0[i][j];
		}
		cout<<"\n";
	}
	cout<<"c0:\n";
	fore(i,0,n){
		fore(k,0,2){
			fore(j,0,n){
				cout<<c0[i][j][k^1]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
	cout<<res0<<"\n";
}

int main(){FIN;
	cin>>n>>m;
	ll q; cin>>q;
	ll fc=n*m;
	fore(i,0,MAXN){
		fore(j,0,MAXN){
			t0[i][j]=1;
		}
	}
	fore(i,0,n){
		fore(j,0,m){
			t0[i+m-j][j]=0;
		}
	}
	fore(i,0,MAXN-1)rec0(i);
	//db(5);
	while(q--){
		ll x,y; cin>>x>>y; x--; y--;
		if(t[x][y]){
			fc++;
		}else{
			fc--;
		}
		t[x][y]^=1;
		t0[x+m-y][y]^=1;
		if(valid(x+m-y-1))rec0(x+m-y-1);
		if(valid(x+m-y))rec0(x+m-y);
		//db(5);
		cout<<res0-fc<<"\n";
	}
	
	return 0;
}