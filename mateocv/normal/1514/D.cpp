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

const int MAXN=300005;

int a[MAXN],c[MAXN];

ll getr(){
	return abs((rand()<<15)^rand());
}

int n,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;};
qu qs[MAXN];
ll ans[MAXN]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}

void add(ll pos){
	c[a[pos]]++;
}

void remove(ll pos){
	c[a[pos]]--;
}

ll get_ans(ll l, ll r){
	ll ca=r-l;
	fore(i,0,min(20,2*n)){
		ll gr=getr()%ca;
		if(c[a[l+gr]]>(ca+1)/2)return c[a[l+gr]]-(ca-c[a[l+gr]]);
	}
	return 1;
}

void mos(){
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    //init();
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans(l,r);
    }
}

int main(){FIN;
	srand(time(NULL));
	cin>>n>>nq;
	fore(i,0,n)cin>>a[i];
	fore(i,0,nq){
		ll l,r; cin>>l>>r; l--;
		qs[i].l=l;
		qs[i].r=r;
	}
	mos();
	fore(i,0,nq)cout<<ans[i]<<"\n";
	
	return 0;
}