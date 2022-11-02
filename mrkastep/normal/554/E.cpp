#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

typedef pair<double,double> point;
typedef long long int ll;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

vector<int> p,t,s[2];

int fs(int v){
    if(p[v]==v) return v;
    int pr=p[v];
    p[v]=fs(pr);
    t[v]^=t[pr];
    return p[v];
}

bool us(int a,int b,int type){
    int a1=fs(a),b1=fs(b);
    if(a1==b1){
        if(t[a]^t[b]^type){
            return false;
        }
        return true;
    }
    p[a1]=b1;
    t[a1]=t[a]^t[b]^type;
    s[0][b1]+=s[t[a1]][a1];
    s[1][b1]+=s[1-t[a1]][a1];
    return true;
}


void solve(int n){
    p.resize(n);
    For(i,n) p[i]=i;
    t.assign(n,0);
    s[0].assign(n,1);
    s[1].assign(n,0);
    bool bad=false;
    int m,a,b,tt;
    scanf("%d",&m);
    For(i,m){
        scanf("%d%d%d",&a,&b,&tt);
        a--;
        b--;
        bad|=!us(a,b,1-tt);
    }
    if(bad){
        printf("0");
        return;
    }
    int c=0;
    For(i,n){
        if(fs(i)==i) c++;
    }
    ll ans=1;
    For(i,c-1){
        ans*=2;
        ans%=mod;
    }
    printf("%I64d",ans);



#ifdef _DEBUG
    printf("\n\nTime: %d\n\n",(ll)1000*clock()/CLOCKS_PER_SEC);
#endif
}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    string s;
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}