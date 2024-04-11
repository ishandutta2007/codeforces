#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

typedef struct item *pitem;
struct item {
	int pr,cnt,val,lazy;
	pitem l,r,f;
	item(int val): pr(rand()),cnt(1),val(val),l(0),r(0),f(0),lazy(0) {}
};
void push(pitem it){
	if(it){
		if(it->lazy){
			it->val=it->lazy;
			if(it->l)it->l->lazy=it->lazy;
			if(it->r)it->r->lazy=it->lazy;
			it->lazy=0;
		}
	}
}
int cnt(pitem t){return t?t->cnt:0;}
int val(pitem t){return t?push(t),t->val:0;}

void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
	}
}

void merge(pitem& t, pitem l, pitem r){
	push(l);push(r);
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),l->r->f=t=l;
	else merge(r->l,l,r->l),r->l->f=t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){
	if(!t){l=r=0;return;}
	push(t);
	if(sz<=cnt(t->l)){
		split(t->l,l,t->l,sz);r=t;
		if(l)l->f=0;
		if(t->l)t->l->f=t;
	}
	else {
		split(t->r,t->r,r,sz-1-cnt(t->l));l=t;
		if(r)r->f=0;
		if(t->r)t->r->f=t;
	}
	upd_cnt(t);
}
void push_all(pitem t){
	if(t->f)push_all(t->f);
	push(t);
}
int getpos(pitem t){
	push_all(t);
	int pos=cnt(t->l);
	while(t->f){
		pitem f=t->f;
		if(t==f->r)pos+=cnt(f->l)+1;
		t=f;
	}
	return pos;
}

// cuantos mas chicos que x
int amlow(pitem t, int x){
	if(!t)return 0;
	push(t);
	
	if(val(t)<x) return cnt(t->l)+1+amlow(t->r,x);
	return amlow(t->l,x);
}

void splitval(pitem t, pitem &l, pitem &r, int val){
	int lef=amlow(t, val);
	split(t,l,r,lef);
}

//kesimo nodo
pitem kth(pitem t, int x){
	push(t);
	if(cnt(t->l)>=x) return kth(t->l,x);
	if(cnt(t->l)+1==x) return t;
	return kth(t->r,x-cnt(t->l)-1);
}

const int MAXN=4e5+10;
pitem pt[MAXN];

void upd(pitem rt, int l, int r, int val){
	pitem x,y,z;
	
	//encontrar pedazo del medio
	splitval(rt, y, z, r+1);
	splitval(y, x, y, l);
	merge(rt,x,z);
	
	//updatear la del medio
	if(y) y->lazy=val;

	
	splitval(rt,x,z,val);
	
	
	merge(rt, x, y);
	merge(rt,rt,z);
}

int main(){FIN;
	int n; cin>>n;
	vector<ii> v(n);
	fore(i,0,n) cin>>v[i].fst,v[i].snd=i;
	
	sort(ALL(v));
	
	pitem rt=0;
	for(auto x:v) pt[x.snd]=new item(x.fst), merge(rt, rt, pt[x.snd]);
	
	int q; cin>>q;
	while(q--){
		int t; cin>>t;
		
		if(t==1){
			int k,w; cin>>k>>w; k--;
			
			int pos=getpos(pt[k]);
			
			//sacar el mio
			pitem l,m,r;
			split(rt, m,r,pos+1);
			split(m,l,m,pos);
			merge(rt,l,r);
			
			//setear valor
			m->lazy=w;
			
			//ponerlo en el nuevo lugar
			splitval(rt,l,r,w);
			merge(rt,l,m);
			merge(rt,rt,r);
		}
		
		if(t==2){
			int k; cin>>k; k--;
			
			push_all(pt[k]);
			cout<<val(pt[k])<<"\n";
		}
		
		if(t==3){
			int l,r; cin>>l>>r;
			
			int m=(l+r)/2;
			upd(rt, l, m, l-1);
			upd(rt, m+1, r, r+1);
		}
		
	}
}