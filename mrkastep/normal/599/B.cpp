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
const int mod=1e5+3;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

int a[100100],b[100100],f[100100],r[100100];

void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    For(i,n){
        scanf("%d",&f[i]);
    }
    For(i,m){
        scanf("%d",&b[i]);
    }
    For(i,100100){
        r[i]=-1;
    }
    For(i,n){
        if(r[f[i]]==-1){
            r[f[i]]=i+1;
        }
        else{
            r[f[i]]=0;
        }
    }
    For(i,m){
        a[i]=r[b[i]];
    }
    For(i,m){
        if(a[i]==-1){
            printf("Impossible");
            return;
        }
    }
    For(i,m){
        if(a[i]==0){
            printf("Ambiguity");
            return;
        }
    }
    printf("Possible\n");
    For(i,m){
        printf("%d ",a[i]);
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