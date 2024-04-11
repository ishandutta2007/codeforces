#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <time.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define ll long long int
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

const int INF=2e9;
const ll LONGINF=4e18;
const double eps=1e-9;

template<typename T>void swap(T *x1,T *x2){
    T t;
    t=*x1;
    *x1=*x2;
    *x2=t;
}

int ex[2020][2020];

void solve(int n){
    vector<pair<int,int>> v;
    pair<int,int> p,t;
    int i,j,ans=0;
    For(i,2020)For(j,2020) ex[i][j]=0;
    For(i,n){
        scanf("%d%d",&p.x,&p.y);
        p.x+=1000;
        p.y+=1000;
        v.pb(p);
        ex[p.x][p.y]=1;
    }
    For(i,n){
        For(j,i){
            if((v[i].x+v[j].x)%2==1||(v[i].y+v[j].y)%2==1) continue;
            ans+=ex[(v[i].x+v[j].x)/2][(v[i].y+v[j].y)/2];


        }
    }
    printf("%d",ans);


#ifndef ONLINE_JUDGE
    printf("\n\nTime in ms: %.0lf",(double)clock() / CLOCKS_PER_SEC * 1000);
#endif
}


int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}