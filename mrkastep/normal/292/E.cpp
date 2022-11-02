#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>

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

int t[1<<18],b[100100],a[100100];

void modify(int v,int l,int r,int l1,int r1,int q){
    if(l1>r1) return;
    if(l==l1&&r==r1){
        t[v]=q;
        return;
    }
    int m=(l+r)/2;
    if(t[v]!=-1){
        modify(2*v,l,m,l,m,t[v]);
        modify(2*v+1,m+1,r,m+1,r,t[v]+m-l+1);
        t[v]=-1;
    }
    if(l1>m){
        modify(2*v+1,m+1,r,l1,r1,q);
        return;
    }
    if(r1<=m){
        modify(2*v,l,m,l1,r1,q);
        return;
    }
    modify(2*v,l,m,l1,m,q);
    modify(2*v+1,m+1,r,m+1,r1,q+m-l1+1);
}

void ask(int v,int l,int r,int pos){
    if(t[v]!=-1){
        printf("%d\n",a[t[v]+pos-l]);
        return;
    }
    if(l==r){
        printf("%d\n",b[l]);
        return;
    }
    int m=(l+r)/2;
    if(pos>m){
        ask(2*v+1,m+1,r,pos);
    }
    else{
        ask(2*v,l,m,pos);
    }
}





void solve(int n){
    int i,m,type,p1,p2,k;
    scanf("%d",&m);
    For(i,n){
        scanf("%d",&a[i]);
    }
    For(i,n){
        scanf("%d",&b[i]);
    }
    For(i,1<<18){
        t[i]=-1;
    }
    For(i,m){
        scanf("%d",&type);
        if(type==1){
            scanf("%d%d%d",&p1,&p2,&k);
            p1--;
            p2--;
            modify(1,0,n-1,p2,p2+k-1,p1);
        }
        else{
            scanf("%d",&k);
            k--;
            ask(1,0,n-1,k);
        }
    }






#ifdef HOME
    printf("\n\nTime in ms: %.0lf\n",clock()/CLOCKS_PER_SEC*1000);
#endif
}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[200200];
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}