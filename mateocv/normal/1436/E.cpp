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
typedef int ll;

const int MAXN=100005;
int n,sq,nq; // array size, sqrt(array size), #queries
ll a[MAXN];
struct qu{int l,r,id;};
qu qs[2*MAXN];
ll ans[2*MAXN]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}

ll tot[400];
ll group[400][400];

ll get_ans(){
	ll pos=-1;
	fore(i,0,400){
		if(tot[i]){
			pos=i;
			break;
		}
	}
	assert(pos!=-1);
	fore(i,0,400){
		if(!group[pos][i])return 400*pos+i;
	}
	assert(0);
}

void add(ll pos){
	ll p0=a[pos]/400,p1=a[pos]%400;
	if(!group[p0][p1]){
		tot[p0]--;
	}
	group[p0][p1]++;
}

void remove(ll pos){
	ll p0=a[pos]/400,p1=a[pos]%400;
	if(group[p0][p1]==1){
		tot[p0]++;
	}
	group[p0][p1]--;
}

void mos(){
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans();
    }
}

vector<ll> g[MAXN];

ll ids[MAXN];

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,n+1)g[i].pb(-1);
	fore(i,0,n)g[a[i]].pb(i);
	fore(i,0,n+1)g[i].pb(n);
	ll va=0;
	fore(i,0,n+1){
		//cout<<i<<":\n";
		fore(j,0,SZ(g[i])-1){
			if(g[i][j]+1<g[i][j+1]){
				qs[va]={g[i][j]+1,g[i][j+1],va};
				//cout<<qs[va].l<<" "<<qs[va].r<<"\n";
				va++;
			}
		}
		ids[i]=va;
	}
	fore(i,0,400)tot[i]=400;
	nq=va;
	assert(nq<=2*n+2);
	mos();
	//fore(i,0,va)cout<<ans[i]<<" "; cout<<"\n";
	va=0;
	fore(i,0,n+1){
		ll br=0;
		fore(j,va,ids[i]){
			if(ans[j]==i){
				br++; break;
			}
		}
		va=ids[i];
		if(!br){
			cout<<i+1<<"\n";
			return 0;
		}
	}
	cout<<n+2<<"\n";
	return 0;
}