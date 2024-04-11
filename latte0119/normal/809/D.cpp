#include<bits/stdc++.h>
using namespace std;

#define int long long

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

struct RBST{
    struct node{
        int val;
        node *lch,*rch;
        int sz;
        int put;
        node(int a):val(a),put(0),lch(0),rch(0),sz(1){}
    };

    RBST():root(NULL){srand((unsigned)time(NULL));}

    node *root;
    inline int getsz(node *t){return t?t->sz:0;}
    inline void push(node *t){
        if(t==NULL)return;
        t->val+=t->put;
        if(t->lch)t->lch->put+=t->put;
        if(t->rch)t->rch->put+=t->put;
        t->put=0;
    }
    inline node *update(node *t){
        if(!t)return NULL;
        t->sz=getsz(t->lch)+getsz(t->rch)+1;
        return t;
    }

    node *merge(node *a,node *b){
        push(a);push(b);
        if(!a)return b;
        if(!b)return a;

        if(rand()%(getsz(a)+getsz(b))<getsz(a)){
            a->rch=merge(a->rch,b);
            return update(a);
        }
        else{
            b->lch=merge(a,b->lch);
            return update(b);
        }
    }

    pair<node *,node *>split(node *t,int k){//[0,k) [k,N)
        push(t);
        if(!t)return make_pair(t,t);
        if(k<=getsz(t->lch)){
            pair<node *,node *>s=split(t->lch,k);
            t->lch=s.second;
            return make_pair(s.first,update(t));
        }
        else{
            pair<node *,node *>s=split(t->rch,k-getsz(t->lch)-1);
            t->rch=s.first;
            return make_pair(update(t),s.second);
        }
    }

    int lower_bound(int x){return lower_bound(root,x);}
    int lower_bound(node *t,int x){
        push(t);
        if(!t)return 0;
        if(t->val>=x)return lower_bound(t->lch,x);
        return lower_bound(t->rch,x)+getsz(t->lch)+1;
    }
    void init(){
        node *a=new node(0);
        node *b=new node(INT_MAX);

        root=merge(a,b);
    }
    void query(int l,int r){
        int k=lower_bound(root,l);
        int kk=lower_bound(root,r);

        node *a,*b,*c,*d;
        pair<node *,node *>s;
        s=split(root,kk);
        c=s.second;
        s=split(s.first,k);
        a=s.first;
        b=s.second;

        node *w=new node(l);
        root=merge(a,w);
        if(b!=NULL){
            b->put++;
            push(b);
        }
        root=merge(root,b);

        s=split(c,1);
        c=s.first;
        d=s.second;
        assert(c!=NULL);
        if(c->val==INT_MAX){
            root=merge(root,c);
        }
        else{
            root=merge(root,d);
        }
    }
    int latte(){
        return getsz(root)-2;
    }

    void dump(){
        dump(root);
        cout<<endl;
    }
    void dump(node *t){
        if(t==NULL)return;
        dump(t->lch);
        cout<<t->val<<" ";
        dump(t->rch);
    }
};

signed main(){
    RBST tree;
    tree.init();
    int N;scanf("%lld",&N);
    rep(i,N){
        int l,r;
        scanf("%lld%lld",&l,&r);
        tree.query(l,r);
    }

    printf("%lld\n",tree.latte());
    return 0;
}