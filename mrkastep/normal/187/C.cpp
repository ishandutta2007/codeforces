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


int p[100100],p2[100100];

int fs(int v){
    if(v==p[v]) return v;
    return p[v]=fs(p[v]);
}

void us(int a,int b){
    a=fs(a);
    b=fs(b);
    p[a]=b;
}

int fs2(int v){
    if(v==p2[v]) return v;
    return p2[v]=fs2(p2[v]);
}

void us2(int a,int b){
    a=fs2(a);
    b=fs2(b);
    p2[a]=b;
}

vector<vector<int>> g;












void solve(int n){
    int a,b,m,k,i,j,l,r,v,ans=0,s,t,dif=0;
    vector<int> d(n,INF),vol,lr(n,-2);
    vector<pair<int,int>> v2,v1;
    queue<int> q;
    g.resize(n);
    scanf("%d%d",&m,&k);
    For(i,n){
        p[i]=i;
        p2[i]=i;
    }
    For(i,k){
        scanf("%d",&a);
        q.push(a-1);
        d[a-1]=0;
        vol.pb(a-1);
        lr[a-1]++;
    }
    For(i,m){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    scanf("%d%d",&s,&t);
    s--;
    t--;
    q.push(t);
    lr[t]++;
    d[t]=0;
    i=0;
    while(!q.empty()){
        while(!q.empty()&&d[q.front()]==i){
            v=q.front();
            q.pop();
            For(j,g[v].size()){
                if(fs(v)!=fs(g[v][j])){
                    v1.pb(mp(g[v][j],v));
                    if(lr[g[v][j]]==-2) lr[g[v][j]]=i;
                    if(lr[g[v][j]]==i-1){
                        v2.pb(mp(fs(g[v][j]),fs(v)));
                    }
                }
                if(d[g[v][j]]==INF){
                    d[g[v][j]]=d[v]+1;
                    q.push(g[v][j]);
                }
            }
        }
        i++;
        For(j,v1.size()){
            us(v1[j].x,v1[j].y);
        }
        For(j,v2.size()){
            us2(v2[j].x,v2[j].y);
        }
        if(fs2(t)==fs2(s)){
            dif++;
            break;
        }
        For(j,v2.size()){
            us(v2[j].x,v2[j].y);
        }
        For(j,v1.size()){
            us2(v1[j].x,v1[j].y);
        }
        if(fs(t)==fs(s)){
            break;
        }
        v1.clear();
        v2.clear();
    }
    if(fs(s)!=fs(t)){
        printf("-1");
    }
    else{
        printf("%d",2*i-dif);
    }






    








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
    char c[100100];
    string s;
    while(scanf("%d",&n)==1) solve(n);
    /*printf("2000 1999 1\n");
    For(n,1999){
        printf("%d %d 1000000000000000\n",n+1,n+2);
    }*/
    return 0;
}