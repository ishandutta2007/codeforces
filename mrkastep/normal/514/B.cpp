#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
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

int p[1010];

int fs(int v){
    if(p[v]==v) return v;
    else return p[v]=fs(p[v]);
}

void us(int a,int b){
    a=fs(a);
    b=fs(b);
    if(a==b) return;
    p[a]=b;
}



void solve(int n){
    pair<int,int> g;
    vector<pair<int,int>> v;
    map<double,int> m;
    double d;
    int i,a,j,b;
    scanf("%d%d",&g.x,&g.y);
    For(i,n){
        scanf("%d%d",&a,&b);
        v.pb(mp(a-g.x,b-g.y));
        p[i]=i;
    }
    int ans=0;
    For(i,n){
        For(j,i){
            if(v[i].x*v[j].y==v[j].x*v[i].y){
                us(i,j);
            }
        }
    }
    For(i,n){
        if(m[fs(i)]==0){
            ans++;
        }
        m[fs(i)]=1;
    }
    printf("%d",ans);


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