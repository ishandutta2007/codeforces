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

typedef struct item *pitem;
struct item {
	int pr,cnt,val;
	pitem l,r,f;
	item(int val): pr(rand()),cnt(1),val(val),l(0),r(0),f(0) {}
};

int cnt(pitem t){return t?t->cnt:0;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
	}
}
void merge(pitem& t, pitem l, pitem r){
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),l->r->f=t=l;
	else merge(r->l,l,r->l),r->l->f=t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){
	if(!t){l=r=0;return;}
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
pitem root(pitem t, ll& pos){ // get root and position for node t
	pos=cnt(t->l);
	while(t->f){
		pitem f=t->f;
		if(t==f->r)pos+=cnt(f->l)+1;
		t=f;
	}
	return t;
}

void print(pitem t){
	if(!t)return;
	print(t->l);
	cout<<t->val<<" ";
	print(t->r);
}

vector<pitem> vt;

int main(){FIN;	
	ll n,q; cin>>n>>q;
	srand(ll(&n));
	vector<ll> p(n);
	fore(i,0,n)cin>>p[i],p[i]--;
	fore(i,0,n)vt.pb(new item(i));
	vector<ll> vis(n);
	fore(i,0,n){
		if(vis[i])continue;
		ll va=i;
		vis[i]=1;
		pitem t=0;
		merge(t,t,vt[i]);
		while(p[va]!=i){
			va=p[va];
			vis[va]=1;
			merge(t,t,vt[va]);
		}
	}
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll x,y; cin>>x>>y; x--; y--;
			//swap(p[x],p[y]);
			ll posx,posy;
			auto rx=root(vt[x],posx);
			auto ry=root(vt[y],posy);
			if(rx==ry){
				if(posx>posy){
					swap(x,y);
					swap(posx,posy);
					swap(rx,ry);
				}
				pitem t0,t1;
				split(rx,rx,t1,posy+1);
				split(rx,rx,t0,posx+1);
				merge(rx,rx,t1);
			}else{
				pitem t0,t1;
				split(rx,rx,t0,posx+1);
				split(ry,ry,t1,posy+1);
				merge(rx,rx,t1);
				merge(rx,rx,ry);
				merge(rx,rx,t0);
			}
		}else{
			ll x,k; cin>>x>>k; x--;
			ll pos;
			auto rx=root(vt[x],pos);
			pos=(pos+k)%cnt(rx);
			pitem t0,t1;
			split(rx,rx,t1,pos+1);
			split(rx,rx,t0,pos);
			cout<<t0->val+1<<"\n";
			merge(rx,rx,t0);
			merge(rx,rx,t1);
		}
		/*
		cout<<"HOLA\n";
		fore(i,0,n){
			if(vt[i]->f==0)
				print(vt[i]),cout<<"\n";
		}
		*/
	}
	
	return 0;
}