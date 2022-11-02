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

struct FT{
    vector<double> t;
    int n;
    FT(){
        n=0;
    }
    FT(int s){
        n=s;
        t.assign(n+1,0);
    }
    int G(int a){return a-(a&(a-1));}

    void add(int p,double v){
        p++;
        for(;p<=n;p+=G(p)) t[p]+=v;
    }

    double ask(int p){
        if(p<0) return 0;
        double ans=0;
        p++;
        p=min(p,n);
        for(;p>0;p-=G(p)) ans+=t[p];
        return ans;
    }





};

FT t[111];



void solve(){
    int n,m,s=0;
    scanf("%d%d",&n,&m);
    For(i,n){
        t[i]=FT(m*n);
    }
    For(i,n){
        int a;
        scanf("%d",&a);
        a--;
        s+=a;
        if(i==0){
            For(j,m){
                if(j!=a){
                    t[i].add(j,(double)1/(m-1));
                }
            }
            continue;
        }
        For(j,n*m){
            t[i].add(j,(t[i-1].ask(j)-t[i-1].ask(j-m)-(t[i-1].ask(j-a)-t[i-1].ask(j-a-1)))/(m-1));
        }
    }
    printf("%.10lf",1+(m-1)*t[n-1].ask(s-1));
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