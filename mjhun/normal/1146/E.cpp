#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;


typedef struct item *pitem;
struct item {
	int pr,cnt;pair<int,int> key;bool rev;
	pitem l,r;
	item(pair<int,int> key):key(key),pr(rand()),cnt(1),l(0),r(0),rev(false) {}
};
int cnt(pitem t){return t?t->cnt:0;}
void upd_cnt(pitem t){if(t)t->cnt=cnt(t->l)+cnt(t->r)+1;}
void push(pitem t){
	if(t&&t->rev){
		t->key=mp(-(t->key.fst),-(t->key.snd));
		swap(t->l,t->r);
		if(t->l)t->l->rev^=true;
		if(t->r)t->r->rev^=true;
		t->rev=false;
	}
}
void split(pitem t, pair<int,int> key, pitem& l, pitem& r){ // l: < key, r: >= key
	push(t);
	if(!t)l=r=0;
	else if(key<t->key)split(t->l,key,l,t->l),r=t;
	else split(t->r,key,t->r,r),l=t;
	upd_cnt(t);
}
void insert(pitem& t, pitem it){
	if(!t)t=it;
	else if(it->pr>t->pr)split(t,it->key,it->l,it->r),t=it;
	else insert(it->key<t->key?t->l:t->r,it);
	upd_cnt(t);
}
void merge(pitem& t, pitem l, pitem r){
	push(l);push(r);
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
void merge2(pitem &t, pitem l, pitem r){
	push(l);push(r);
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr){
		pitem p1=l->l, p2=l->r, p3, p4;
		split(r,l->key,p3,p4);
		merge2(l->l,p1,p3);
		merge2(l->r,p2,p4);
		t=l;
	}else{
		pitem p1=r->l, p2=r->r,p3,p4;
		split(l,r->key,p3,p4);
		merge2(r->l,p1,p3);
		merge2(r->r,p2,p4);
		t=r;
	}
	upd_cnt(t);
}

int n,q;
int r[100005];

void asd(pitem t){
	if(!t)return;
	push(t);
	r[abs(t->key.snd)]=t->key.fst;
	asd(t->l);asd(t->r);
}

int main(){
	srand(time(0));
	scanf("%d%d",&n,&q);
	pitem t=0;
	fore(i,0,n){
		int a;
		scanf("%d",&a);
		insert(t,new item(mp(a,i)));
	}
	while(q--){
		char s[4];int x;
		scanf("%s%d",s,&x);
		if(s[0]=='<'){
			auto p=mp(x-1,1<<30);
			pitem a,b;
			split(t,p,a,b);
			if(a)a->rev^=true;
			merge2(t,a,b);
		}
		else {
			auto p=mp(x,1<<30);
			pitem a,b;
			split(t,p,a,b);
			if(b)b->rev^=true;
			merge2(t,a,b);
		}
	}
	asd(t);
	fore(i,0,n)printf("%d%c",r[i]," \n"[i==n-1]);
	return 0;
}