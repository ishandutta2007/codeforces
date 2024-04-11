#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e9;
const double eps=1e-9;

int t[2000000];
vector<pair<int,int>> pr;

void build(int v,int l,int r){
    if(l==r){
        t[v]=pr[l].y-pr[l].x;
        return;
    }
    int m=(l+r)/2;
    build(2*v,l,m);
    build(2*v+1,m+1,r);
    t[v]=min(t[2*v],t[2*v+1]);
}

int ask(int v,int l,int r,int l1,int r1){
    if(l1>r1){
        return INF;
    }
    if(l==l1&&r==r1){
        return t[v];
    }
    int m=(l+r)/2;
    return min(ask(2*v,l,m,l1,min(m,r1)),ask(2*v+1,m+1,r,max(m+1,l1),r1));
}




void solve(int n){
    int i,a,k,l,r,p,q,il,ir,c;
    map<int,vector<int>> pos;
    map<int,int> m;
    scanf("%d",&k);
    For(i,n){
        scanf("%d",&a);
        pos[a].pb(i);
    }
    for(auto it=pos.begin();it!=pos.end();it++){
        For(i,it->y.size()-1){
            m[it->y[i]]=it->y[i+1];
        }
    }
    auto it=m.begin(),it1=m.begin();
    while(it!=m.end()){
        it1=next(it);
        if(it1!=m.end()&&it1->y<it->y){
            if(it==m.begin()){
                m.erase(it);
                it=m.begin();
                continue;
            }
            it1=prev(it);
            m.erase(it);
            it=it1;
            continue;
        }
        it++;
    }
    for(it=m.begin();it!=m.end();it++){
        pr.pb(*it);
    }
    if(pr.empty()){
        For(i,k){
            printf("-1\n");
        }
        return;
    }
    build(1,0,pr.size()-1);
    For(i,k){
        scanf("%d%d",&p,&q);
        p--;
        q--;
        l=-1;
        r=pr.size()-1;
        while(r-l>1){
            c=(l+r)/2;
            if(pr[c].x<p){
                l=c;
            }
            else{
                r=c;
            }
        }
        il=r;
        if(pr[il].x<p){
            printf("-1\n");
            continue;
        }
        l=0;
        r=pr.size();
        while(r-l>1){
            c=(l+r)/2;
            if(pr[c].y>q){
                r=c;
            }
            else{
                l=c;
            }
        }
        ir=l;
        if(pr[ir].y>q){
            printf("-1\n");
            continue;
        }
        a=ask(1,0,pr.size()-1,il,ir);
        if(a==INF){
            printf("-1\n");
        }
        else{
            printf("%d\n",a);
        }
    }


}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#else
    if(0){
        freopen("expedition.in","rt",stdin);
        freopen("expedition.out","wt",stdout);
    }
#endif
    int n;
    ll a;
    char c[300];
    string s;
    scanf("%d",&n);
    solve(n);
    /*printf("500000 500000\n");
    For(n,500000){
        printf("1 ");
    }
    For(n,500000){
        printf("\n1 500000");
    }*/

    return 0;
}