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

ll n,m,t; 

ll val(ll i, ll j){
	return (i>=0)&&(i<n)&&(j>=0)&&(j<m);
}

int main(){FIN;
	cin>>n>>m>>t;
	char c[n][m];
	fore(i,0,n){
		fore(j,0,m){
			cin>>c[i][j];
		}
	}
	short d[n][m];
	mset(d,0);
	bool vis[n][m];
	mset(vis,false);
	queue<pair<short,short>> q;
	ll tot=0;
	fore(i,0,n){
		fore(j,0,m){
			if(val(i+1,j)&&c[i][j]==c[i+1][j])vis[i][j]=1,q.push({i,j}),tot++;
			else if(val(i-1,j)&&c[i][j]==c[i-1][j])vis[i][j]=1,q.push({i,j}),tot++;
			else if(val(i,j+1)&&c[i][j]==c[i][j+1])vis[i][j]=1,q.push({i,j}),tot++;
			else if(val(i,j-1)&&c[i][j]==c[i][j-1])vis[i][j]=1,q.push({i,j}),tot++;
		}
	}
	if(tot==0){
		while(t--){
			ll i,j,p; cin>>i>>j>>p; i--; j--;
			cout<<c[i][j]<<"\n";
		}
		return 0;
	}
	/*fore(i,0,n){
		fore(j,0,m){
			cout<<vis[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	while(SZ(q)){
		auto f=q.front(); q.pop();
		ll i=f.fst, j=f.snd;
		//cout<<i<<" "<<j<<"\n";
		if(val(i+1,j)&&!vis[i+1][j]){
			vis[i+1][j]=1;
			d[i+1][j]=d[i][j]+1;
			q.push({i+1,j});
		}
		if(val(i-1,j)&&!vis[i-1][j]){
			vis[i-1][j]=1;
			d[i-1][j]=d[i][j]+1;
			q.push({i-1,j});
		}
		if(val(i,j+1)&&!vis[i][j+1]){
			vis[i][j+1]=1;
			d[i][j+1]=d[i][j]+1;
			q.push({i,j+1});
		}
		if(val(i,j-1)&&!vis[i][j-1]){
			vis[i][j-1]=1;
			d[i][j-1]=d[i][j]+1;
			q.push({i,j-1});
		}
	}
	/*fore(i,0,n){
		fore(j,0,m){
			cout<<d[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	while(t--){
		ll i,j,p; cin>>i>>j>>p; i--; j--;
		if(p<=d[i][j])cout<<c[i][j]<<"\n";
		else{
			if((p-d[i][j])&1)cout<<(char)('1'-c[i][j]+'0')<<"\n";
			else cout<<c[i][j]<<"\n";
		}
	}
	
	
	return 0;
}