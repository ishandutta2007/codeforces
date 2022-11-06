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

const int MAXN=1000006;

bool isprime[MAXN];
vector<ll> prime;
int SPF[MAXN];
 
//Inicializar en true isprime
void sieve(int n){
    isprime[0] = isprime[1] = false;
    fore(i,2,n+1){
        if(isprime[i]) prime.push_back(i), SPF[i] = i;
        for(int j=0; j<SZ(prime)&&i*prime[j]<=n&&prime[j]<=SPF[i]; j++){
            isprime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}

vector<ll> pr(ll n){
	vector<ll> res;
	while(n>1){
		ll s=SPF[n];
		res.pb(s);
		while(n%s==0)n/=s;
	}
	return res;
}

int pa[2*MAXN],sz[2*MAXN];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

ll ub[MAXN];

struct query{
	ll x,y,id;
};

bool cmp(query a, query b){
	return pair<ll,ll>({a.x,a.y})<pair<ll,ll>({b.x,b.y});
}

bool eq(query a, query b){
	return pair<ll,ll>({a.x,a.y})==pair<ll,ll>({b.x,b.y});
}


int main(){FIN;
	mset(isprime,true);
	sieve(MAXN);
	ll n,q; cin>>n>>q;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,SZ(prime)){
		ub[prime[i]]=n+i;
	}
	dsu_init(n+SZ(prime));
	fore(i,0,n){
		auto p=pr(a[i]);
		for(auto j:p)join(ub[j],i);
	}
	vector<query> vq;
	fore(i,0,q){
		ll x,y; cin>>x>>y; x--; y--;
		vq.pb({x,y,i});
	}
	vector<ll> res(q,2);
	for(auto i:vq){
		if(find_pa(i.x)==find_pa(i.y)){
			res[i.id]=0;
		}
	}
	fore(i,0,q){
		vq[i].x=find_pa(vq[i].x);
		vq[i].y=find_pa(vq[i].y);
		if(vq[i].x>vq[i].y)swap(vq[i].x,vq[i].y);
	}
	vector<query> val;
	fore(i,0,n){
		//cout<<i<<":\n";
		auto v=pr(a[i]+1);
		fore(j,0,SZ(v))v[j]=ub[v[j]];
		v.pb(i);
		fore(j,0,SZ(v))v[j]=find_pa(v[j]);
		sort(ALL(v));
		//for(auto j:v)cout<<j<<" ";
		//cout<<"\n";
		fore(ii,0,SZ(v)){
			fore(jj,ii+1,SZ(v)){
				val.pb({v[ii],v[jj],-1});
			}
		}
	}
	sort(ALL(vq),cmp);
	sort(ALL(val),cmp);
	
	ll l=0,r=0;
	while(l<SZ(vq)&&r<SZ(val)){
		if(eq(vq[l],val[r])){
			res[vq[l].id]=min(res[vq[l].id],1ll);
			l++;
		}else if(cmp(vq[l],val[r])){
			l++;
		}else{
			r++;
		}
	}
	for(auto i:res)cout<<i<<"\n";
	return 0;
}