#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <math.h>
#include <complex>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=1e9;
const int mod=123456789;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

int a[100100],d[100100];

struct ft{
    int n;
    vector<pair<int,int>> tl,tr;
    ft(){
        n=0;
    }
    ft(int s){
        n=s+1;
        tl.assign(n,mp(0,0));
        tr.assign(n,mp(0,0));
    }
    int G(int a){return a-(a&(a-1));}
    void add(int p,pair<int,int> v){
        for(int i=p+1;i<n;i+=G(i)) tl[i]=max(tl[i],v);
        for(int i=p+1;i>0;i-=G(i)) tr[i]=max(tr[i],v);
    }
    pair<int,int> ask(int l,int r){
        pair<int,int> ans=mp(0,0);
        l++;
        int i;
        for(i=r;i-G(i)>=l;i-=G(i)) ans=max(ans,tl[i]);
        if(mp(d[i-1],i-1)>ans) ans=mp(d[i-1],i-1);
        for(i=l;i+G(i)<=r;i+=G(i)) ans=max(ans,tr[i]);
        return ans;
    }
};

int n;
ft T;

ll ans(int l,int r){
    if(l==r) return 0;
    pair<int,int> mx=T.ask(l,r);
    return (ll)mx.x*(mx.y-l+1)*(r-mx.y)+ans(l,mx.y)+ans(mx.y+1,r);
}

void solve(){
    int q,l,r,c;
    scanf("%d%d",&n,&q);
    For(i,n){
        scanf("%d",&a[i]);
    }
    For(i,n-1){
        d[i]=abs(a[i]-a[i+1]);
    }
    T=ft(n-1);
    For(i,n-1){
        T.add(i,mp(d[i],i));
    }
    For(i,q){
        scanf("%d%d",&l,&r);
        l--;
        r--;
        printf("%I64d\n",ans(l,r));
    }
}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    solve();
    return 0;
}