#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define M 100000
using namespace std;

typedef long long ll;

ll x,k;
vector<ll> sol;
vector<pair<ll,int> > f;
vector<ll> d;
vector<int> g[7005];

void grec(int k, ll c){
	if(k==f.size()){d.pb(c);return;}
	grec(k+1,c);
	fore(i,0,f[k].snd){
		c*=f[k].fst;
		grec(k+1,c);
	}
}

void gendiv(ll x){
	for(ll i=2;i*i<=x;++i){
		if(x%i==0){
			int q=0;
			while(x%i==0){
				x/=i;
				q++;
			}
			f.pb(mp(i,q));
		}
	}
	if(x>1)f.pb(mp(x,1));
	grec(0,1);
	sort(d.begin(),d.end());
	fore(i,0,d.size()){
		fore(j,i,d.size()){
			if(d[j]%d[i]==0)g[j].pb(i);
		}
	}
}

map<pair<int,int>,pair<int,int> > w;

void dfs(int x, int k){
	if(!k){sol.pb(d[x]);return;}
	if(w.count(mp(x,k))){
		pair<int,int> p=w[mp(x,k)];
		fore(i,p.fst,p.snd){
			sol.pb(sol[i]);
			if(sol.size()==M)break;
		}
		return;
	}
	int s=sol.size();
	fore(i,0,g[x].size()){
		int y=g[x][i];
		dfs(y,k-1);
		if(sol.size()==M)break;
	}
	int e=sol.size();
	w[mp(x,k)]=mp(s,e);
}

int main(){
	scanf("%I64d%I64d",&x,&k);
	if(k>=M){
		if(x>1)fore(i,0,M)sol.pb(1);
		else sol.pb(1);
	}
	else {
		gendiv(x);
		dfs(d.size()-1,k);
	}
	fore(i,0,sol.size()){
		if(i)putchar(' ');
		printf("%I64d",sol[i]);
	}
	puts("");
	return 0;
}