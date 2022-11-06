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

vector<ll> a,b;

ll vis[300005],d[300005][2];
pair<ll,ll> p[300005][2];

ll n;

void bfs(){
	ll uvis=n+1;
	queue<pair<ll,ll>> q;
	q.push({n,0});
	vis[n]=1;
	p[n][0]={-1,-1};
	while(SZ(q)){
		auto f=q.front(); q.pop();
		//cout<<f.fst<<" "<<f.snd<<endl;
		if(!f.fst)continue;
		if(f.snd==1){
			ll x=f.fst+b[f.fst-1];
			if(!vis[x]){
				q.push({x,0});
				vis[x]=1;
				d[x][0]=d[f.fst][f.snd]+1;
				p[x][0]=f;
			}
		}else{
			//cout<<f.fst<<" "<<f.snd<<" "<<uvis<<endl;
			fore(i,f.fst-a[f.fst-1],uvis){
				q.push({i,1});
				d[i][1]=d[f.fst][f.snd]+1;
				p[i][1]=f;
			}
			uvis=min(f.fst-a[f.fst-1],uvis);
		}
	}
}

int main(){FIN;
	cin>>n;
	a.resize(n);
	b.resize(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	d[0][1]=1e18;
	bfs();
	auto res=d[0][1];
	if(res>1e17){
		cout<<"-1\n";
		return 0;
	}
	cout<<(res+1)/2<<"\n";
	/*
	fore(i,0,n+1){
		fore(j,0,2){
			cout<<i<<" "<<j<<" : "<<p[i][j].fst<<" "<<p[i][j].snd<<endl;
		}
	}
	return 0;
	*/
	vector<ll> vres;
	ll va=0;
	while(va!=-1){
		//cout<<va<<endl;
		vres.pb(va);
		va=p[va][1].fst;
		va=p[va][0].fst;
	}
	reverse(ALL(vres));
	for(auto i:vres)cout<<i<<" ";
	cout<<"\n";
	
	return 0;
}