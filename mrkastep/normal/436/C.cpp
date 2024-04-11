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

int p[1010];

int fs(int v){
    if(p[v]==v){
        return v;
    }
    return p[v]=fs(p[v]);
}

void us(int a,int b){
    a=fs(a);
    b=fs(b);
    p[a]=b;
}






int t[1010][11][11];

int cmp(int i1,int i2,int n,int m){
    int i,j,ans=0;
    For(i,n){
        For(j,m){
            if(t[i1][i][j]!=t[i2][i][j]) ans++;
        }
    }
    return ans;
}

struct edge{
    int c,a,b;
};


bool operator<(edge e1,edge e2){
    return e1.c<e2.c;
}

vector<edge> e;
vector<vector<int>> g;
bool st[1010];

void deep(int v,int pr){
    int i;
    st[v]=false;
    printf("%d %d\n",v+1,pr+1);
    For(i,g[v].size()){
        if(st[g[v][i]]){
            deep(g[v][i],v);
        }
    }
}




void solve(int n){
    int m,k,c,i,j,l,ans=0,r=0;
    edge one;
    scanf("%d%d%d",&m,&k,&c);
    g.resize(k);
    getchar();
    For(l,k){
        For(i,n){
            For(j,m){
                t[l][i][j]=getchar();
            }
            getchar();
        }
    }
    For(i,k){
        For(j,i){
            one.a=i;
            one.b=j;
            one.c=cmp(i,j,n,m);
            e.pb(one);
        }
    }
    For(i,k) p[i]=i;
    sort(all(e));
    For(i,e.size()){
        if(fs(e[i].a)!=fs(e[i].b)){
            if(e[i].c*c>=n*m) break;
            r++;
            g[e[i].a].pb(e[i].b);
            g[e[i].b].pb(e[i].a);
            ans+=e[i].c;
            us(e[i].a,e[i].b);
        }
    }
    printf("%d\n",ans*c+n*m*(k-r));
    For(i,k){
        st[i]=true;
    }
    For(i,k){
        if(st[i]){
            deep(i,-1);
        }
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