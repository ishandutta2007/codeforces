#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<=(b);i++)
#define pb push_back
#define ll long long

int d[5100][5100],sb[5100][5100];
const int mod=1000000007;

void solve(int n){
    int i,j,k,a,b;
    scanf("%d%d%d",&a,&b,&k);
    a;
    b;
    For(i,5100) For(j,5100){
        d[i][j]=0;
        sb[i][j]=0;
    }
    d[0][a]=1;
    FOR(i,a,n) sb[0][i]=1;
    FOR(i,1,k){
        FOR(j,1,n){
            if(j<b){
                d[i][j]=sb[i-1][j+(b-j-1)/2]-d[i-1][j]+mod;
                d[i][j]%=mod;
            }
            if(j>b){
                d[i][j]=sb[i-1][n]-sb[i-1][b+(j-b)/2]+mod;
                d[i][j]%=mod;
                d[i][j]-=d[i-1][j]-mod;
                d[i][j]%=mod;
            }
            if(j==b){
                d[i][j]=0;
            }
            if(j==1) sb[i][j]=d[i][j];
            else sb[i][j]=sb[i][j-1]+d[i][j];
            d[i][j]%=mod;
            sb[i][j]%=mod;
        }
    }
    printf("%d\n",sb[k][n]);
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    while(scanf("%d",&n)!=EOF){
        solve(n);
        printf("\n\n");
    }
    return 0;
}