#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

struct Node {
    int value;
    int le, ri;
    int min, max, h;
    long long T, Z;
    Node *P, *L, *R;
};

bool cmp1(Node *n1, Node *n2) {
    return n1->le < n2->le; 
}

Node * node[100010];
Node * root;
int n;
int m;
Node* leavelist[100010];
int nl;

int main() {
    scanf("%d", &n);
    For(i,1,n) node[i] = new Node();
//  set<int> se;
    For(i,1,n) {
        int fa, va;
        scanf("%d%d", &fa, &va);        
        /*if(!se.count(va)) se.insert(va);
        else while(1);
        if(va <= 0 || va > 1000000000) while(1); */
        node[i]->L = node[i]->R = NULL;
        node[i]->value = va;
        node[i]->T=node[i]->Z=0;
        if(fa==-1) node[i]->P = NULL;
        else {
            node[i]->P = node[fa];  
        }
        if(fa==-1)root=node[i];
    }   
    For(i,1,n) if(node[i]->P != NULL) {
        Node * P = node[i]->P;
        if(P->value > node[i]->value) P->L=node[i];
        else P->R=node[i];
    }
    {
        vector<Node*> q;
        q.pb(root);
        root->le=0,root->ri=2000000000;
        root->h=0;
        for(int i=0;i<q.size();++i){
            Node * p = q[i];
            int v=p->value;
            if(p->L!=NULL){
                p->L->le=p->le;
                p->L->ri=v-1;
                p->R->le=v+1;
                p->R->ri=p->ri;
                p->L->h=p->R->h=p->h+1;
                q.pb(p->L);
                q.pb(p->R);
            }       
            else {
                leavelist[nl++] = p;
            }   
        }
        for(int i=q.size()-1;i>=0;--i){
            Node *p=q[i];
            if(p->L==NULL) {
                p->min=p->max=p->value;
            }
            else {
                p->min=min(p->L->min,p->R->min);
                p->max=max(p->L->max,p->R->max);
                p->T=p->L->max+p->R->min;
            }
        }
        for(int i=q.size()-1;i>=0;--i) {
            Node *p=q[i];
            Node *P =p->P;
            if(P!=NULL) {
                if(p == P->L) p->T -= p->max;
                else p->T -= p->min;
            }
        }
        for(int i=0;i<q.size();++i){
            Node *p=q[i];
            p->Z=p->T;
            if(p->P!=NULL) p->Z+=p->P->Z;
        }
    }
//  For(i,1,n) cout << node[i]->le << " " << node[i]->ri << endl;
    sort(leavelist, leavelist+nl, cmp1);
    scanf("%d", &m);
    Rep(i,m) {
        int v;
        scanf("%d", &v);
        
        /*if(!se.count(v)) se.insert(v);
        else while(1);
        if(v <= 0 || v > 1000000000) while(1);*/

        
        int L = 0, R = nl - 1;
        while(L < R) {
            int M = (L + R) / 2 + 1;
            if(leavelist[M]->le <= v) L = M;
            else R = M - 1; 
        }
        // if(!(leavelist[L]->le <= v && v <= leavelist[L]->ri)) while(1);
        double res = leavelist[L]->Z;
        res /= leavelist[L]->h;
        printf("%.10f\n", res);
    }

    return 0;
}