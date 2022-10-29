#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define hash THXDEM
using namespace std;
typedef long long ll;

typedef struct item *pitem;
struct item {
	int pr;pair<ll,ll> key;int cnt;
	pitem l,r;
	item(pair<ll,ll> key):key(key),pr(rand()),cnt(1),l(0),r(0) {}
};
pitem cp(pitem t){
	if(!t)return t;
	pitem tt=new item(t->key);
	tt->pr=t->pr;tt->l=t->l;tt->r=t->r;tt->cnt=t->cnt;
	return tt;
}
int cnt(pitem t){return t?t->cnt:0;}
pitem upd_cnt(pitem t){if(t)t->cnt=cnt(t->l)+cnt(t->r)+1;return t;}
void split(pitem t, pair<ll,ll> key, pitem& l, pitem& r){
	if(!t){l=r=0;return;}
	pitem tt=cp(t);
	if(key<t->key)split(t->l,key,l,tt->l),r=tt;
	else split(t->r,key,tt->r,r),l=tt;
	upd_cnt(tt);
}
pitem insert(pitem t, pitem it){
	if(!t)return it;
	if(it->pr>t->pr){
		pitem it2=cp(it);
		split(t,it->key,it2->l,it2->r);
		return upd_cnt(it2);
	}
	else {
		pitem tt=cp(t);
		if(it->key<t->key)tt->l=insert(t->l,it);
		else tt->r=insert(t->r,it);
		return upd_cnt(tt);
	}
}
pitem merge(pitem l, pitem r){
	pitem t;
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr){
		t=cp(l);
		t->r=merge(l->r,r);
	}
	else {
		t=cp(r);
		t->l=merge(l,r->l);
	}
	return upd_cnt(t);
}
pitem erase(pitem t, pair<ll,ll> key){
	if(!t)return t;
	if(t->key==key)return merge(t->l,t->r);
	pitem tt=cp(t);
	if(key<t->key)tt->l=erase(t->l,key);
	else tt->r=erase(t->r,key);
	return upd_cnt(tt);
}
pair<int,pair<ll,ll> > lb(pitem t, pair<ll,ll> key){
	if(!t)return mp(0,mp(-1LL,-1LL));
	if(key>t->key){
		auto w=lb(t->r,key);w.fst+=cnt(t->l)+1;return w;
	}
	auto w=lb(t->l,key);
	if(w.fst==cnt(t->l))w.snd=t->key;
	return w;
}

pitem t0[100005],t1[100005];
int n;

ll hash(char *s){
	ll p=131,MOD0=1001001011,MOD1=1000000009;
	ll r0=0,r1=0;
	for(int i=0;s[i];++i){
		r0=(r0*p+s[i])%MOD0;
		r1=(r1*p+s[i])%MOD1;
	}
	return (r0<<31)|r1;
}

void rem(int i, ll w){
	auto p=lb(t0[i],mp(w,-1)).snd;
	if(p.fst!=w)return;
	t0[i]=erase(t0[i],p);
	t1[i]=erase(t1[i],mp(p.snd,p.fst));
}

int main(){
	scanf("%d",&n);
	fore(i,1,n+1){
		t0[i]=t0[i-1];t1[i]=t1[i-1];
		char s[16];
		scanf("%s",s);
		if(s[0]=='s'){
			ll v;
			scanf("%s%lld",s,&v);
			ll w=hash(s);
			rem(i,w);
			t0[i]=insert(t0[i],new item(mp(w,v)));
			t1[i]=insert(t1[i],new item(mp(v,w)));
			assert(t0[i]&&t1[i]);
		}
		else if(s[0]=='r'){
			scanf("%s",s);
			rem(i,hash(s));
		}
		else if(s[0]=='q'){
			scanf("%s",s);
			ll w=hash(s);
			auto p=lb(t0[i],mp(w,-1)).snd;
			if(p.fst!=w)puts("-1");
			else printf("%d\n",lb(t1[i],mp(p.snd,-1)).fst);
			fflush(stdout);
		}
		else if(s[0]=='u'){
			int d;
			scanf("%d",&d);
			t0[i]=t0[i-d-1];
			t1[i]=t1[i-d-1];
		}
		else {assert(0);}
	}
	return 0;
}