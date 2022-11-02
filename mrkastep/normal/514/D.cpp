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

int t[5][150000],a[5][100100];

void build(int ind,int v,int l,int r){
    if(l==r){
        t[ind][v]=a[ind][l];
        return;
    }
    int c=(l+r)/2;
    build(ind,2*v,l,c);
    build(ind,2*v+1,c+1,r);
    t[ind][v]=max(t[ind][2*v],t[ind][2*v+1]);
}

int ask(int ind,int v,int l,int r,int l1,int r1){
    if(l1>r1){
        return -INF;
    }
    if(l1==l&&r1==r){
        return t[ind][v];
    }
    int c=(l+r)/2;
    return max(ask(ind,2*v,l,c,l1,min(r1,c)),ask(ind,2*v+1,c+1,r,max(l1,c+1),r1));
}






void solve(int n){
    int i,m,k,j,ans[5],ans1[5],s,l,r;
    bool g;
    scanf("%d%d",&m,&k);
    For(i,n){
        For(j,m){
            scanf("%d",&a[j][i]);
        }
    }
    For(i,m){
        build(i,1,0,n-1);
        ans[i]=0;
    }
    r=n+1;
    l=0;
    while(r-l>1){
        int c=(l+r)/2;
        g=false;
        For(i,n-c+1){
            s=0;
            For(j,m){
                ans1[j]=ask(j,1,0,n-1,i,i+c-1);
                s+=ans1[j];
            }
            if(s<=k){
                For(j,m){
                    ans[j]=ans1[j];
                }
                g=true;
                break;
            }
        }
        if(g) l=c;
        else r=c;
    }
    For(i,m){
        printf("%d ",ans[i]);
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
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}