#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

uint32_t xor128(){
    static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

struct node{
    node *l,*r;
    int cnt;
    int v;
};


const int POOL_SIZE=20000000;
node pool[POOL_SIZE];
int tail;
node *alloc(){
    assert(tail<POOL_SIZE);
    return &pool[tail++];
}

inline int count(node *t){
    return t?t->cnt:0;
}

inline node *update(node *t){
    if(!t)return t;
    t->cnt=count(t->l)+1+count(t->r);
    return t;
}

node *merge(node *a,node *b){
    if(!a)return b;
    if(!b)return a;

    if(xor128()%(count(a)+count(b))<count(a)){
         node *x=alloc();
         x->v=a->v;
         x->l=a->l;
         x->r=merge(a->r,b);
         return update(x);
    }
    else{
        node *x=alloc();
        x->v=b->v;
        x->r=b->r;
        x->l=merge(a,b->l);
        return update(x);
    }
}

pair<node *,node *>split(node *t,int k){
    if(!t)return {(node *)NULL,(node *)NULL};
    if(k<=count(t->l)){
        pair<node *,node *>s=split(t->l,k);
        node *x=alloc();
        x->v=t->v;
        x->r=t->r;
        x->l=s.second;
        return {s.first,update(x)};
    }
    else{
        pair<node *,node *>s=split(t->r,k-count(t->l)-1);
        node *x=alloc();
        x->v=t->v;
        x->l=t->l;
        x->r=s.first;
        return {update(x),s.second};
    }
}

node *root[111111];


int lb(node *t,int k){
    if(!t)return 0;
    if(t->v<k){
        return 1+count(t->l)+lb(t->r,k);
    }
    return lb(t->l,k);
}

int ub(node *t,int k){
    if(!t)return 0;
    if(t->v<=k){
        return 1+count(t->l)+ub(t->r,k);
    }
    return ub(t->l,k);
}

node *ins(node *t,int v){
    int c=lb(t,v);
    pair<node *,node *>s=split(t,c);

    node *x=alloc();
    x->v=v;
    x->l=x->r=NULL;
    x->cnt=1;
    return merge(s.first,merge(x,s.second));
}

node *er(node *t,int v){
    int c=lb(t,v);
    pair<node *,node *>s1=split(t,c);
    pair<node *,node *>s2=split(s1.second,1);
    return merge(s1.first,s2.second);
}

template<class T>
class Array {
public:
	Array() {}

	Array(int n) {
		h = 0;
		for (int i = 1; i < n; i *= 16) h += 4;
	}

	T *mutable_get(int k) {
		auto p = mutable_get(k, root, 0, h);
		root = p.first;
		return &p.second->value;
	}

	T immutable_get(int k) {
		return immutable_get(k, root, 0, h)->value;
	}

private:
	struct node {
		node *ch[16] = {};
		T value;

		node() {}
		node(T value) : value(value) {}
	};

	int h;
	node *root = nullptr;

	node *immutable_get(int a, node *x, int l, int d) {
		if (d == 0) return x;
		int id = (a - l) >> (d - 4);
		return immutable_get(a, x->ch[id], l + (id << (d - 4)), d - 4);
	}

	pair<node *, node *> mutable_get(int a, node *x, int l, int d) {
		x = x != nullptr ? new node(*x) : new node();
		if (d == 0) return make_pair(x, x);
		int id = (a - l) >> (d - 4);
		auto p = mutable_get(a, x->ch[id], l + (id << (d - 4)), d - 4);
		x->ch[id] = p.first;
		return make_pair(x, p.second);
	}
};


void deb(node *t){
    if(!t)return;
    deb(t->l);
    cout<<t->v<<" ";
    deb(t->r);
}
void debug(node *t){
    deb(t);
    cout<<endl;
}


signed main(){
    int Q;scanf("%d",&Q);

    map<string,int>mp;
    root[0]=NULL;
    vector<Array<int>>val(111111);
    val[0]=Array<int>(111111);
    rep(i,111111){
        *val[0].mutable_get(i)=-1;
    }
    char buf[22],buf2[22];
    rep(i,Q){
        string s,t;

        scanf(" %s",buf);
        s=buf;
        int v;
        if(s!="undo"){
            scanf(" %s",buf2);
            t=buf2;
            if(mp.find(t)!=mp.end())v=mp[t];
            else{
                v=mp.size();
                mp[t]=v;
            }
        }



        root[i+1]=root[i];
        val[i+1]=val[i];

        if(s=="set"){
            int x;scanf("%d",&x);
            if(val[i+1].immutable_get(v)!=-1){
                root[i+1]=er(root[i+1],val[i+1].immutable_get(v));
            }
            root[i+1]=ins(root[i+1],x);
            *val[i+1].mutable_get(v)=x;
        }
        else if(s=="remove"){
            if(val[i+1].immutable_get(v)>=0){
                root[i+1]=er(root[i+1],val[i+1].immutable_get(v));
                *val[i+1].mutable_get(v)=-1;
            }
        }
        else if(s=="query"){
            if(val[i+1].immutable_get(v)==-1)puts("-1");
            else printf("%d\n",lb(root[i+1],val[i+1].immutable_get(v)));
        }
        else{
            int x;scanf("%d",&x);
            root[i+1]=root[i-x];
            val[i+1]=val[i-x];
        }
        /*
        debug(root[i+1]);
        rep(j,mp.size())cout<<val[i+1].immutable_get(j)<<" ";cout<<endl;
        cout<<"---------------"<<endl;
        */
        fflush(stdout);
    }
    return 0;
}