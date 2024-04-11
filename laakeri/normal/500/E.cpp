#include <iostream>
#include <vector>
#define F first
#define S second

using namespace std;

typedef struct node* pnode;
struct node{
    int v;
    pnode l,r;
    node(){
        v=0;
        l=0;
        r=0;
    }
};

const int N=1<<30;

void setv(pnode&, int, int, int, int);
void golazy(pnode t, int l, int r){
    if (t->v==r-l+1){
        int m=(l+r)/2;
        setv(t->l, l, m, l, m);
        setv(t->r, m+1, r, m+1, r);
    }
}

int val(pnode t){
    if (t) return t->v;
    else return 0;
}

void setv(pnode&t, int l, int r, int ql, int qr){
    if (qr<l||ql>r) return;
    if (!t){
        t=new node;
    }
    if (ql<=l&&r<=qr){
        t->v=r-l+1;
    }
    else{
        golazy(t, l, r);
        int m=(l+r)/2;
        setv(t->l, l, m, ql, qr);
        setv(t->r, m+1, r, ql, qr);
        t->v=val(t->l)+val(t->r);
    }
}

int getv(pnode t, int l, int r, int ql, int qr){
    if (qr<l||ql>r) return 0;
    if (!t) return 0;
    if (ql<=l&&r<=qr){
        return t->v;
    }
    else{
        golazy(t, l, r);
        int m=(l+r)/2;
        return getv(t->l, l, m, ql, qr)+getv(t->r, m+1, r, ql, qr);
    }
}

int x[200001];
int y[200001];

vector<pair<int, int> > qas[200001];
int v[200001];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pnode root=new node;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        qas[a].push_back({b, i});
    }
    for (int i=n;i>=1;i--){
        setv(root, 0, N-1, x[i], min(N-1, x[i]+y[i]-1));
        for (auto qq:qas[i]){
            v[qq.S]=x[qq.F]-x[i]+1-getv(root, 0, N-1, x[i], x[qq.F]);
        }
    }
    for (int i=0;i<q;i++){
        cout<<v[i]<<'\n';
    }
}