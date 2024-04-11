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



void solve(int a){
    int b,s;
    scanf("%d%d",&b,&s);
    if(abs(a+b)%2!=abs(s)%2||abs(a)+abs(b)>s){
        printf("No");
    }
    else{
        printf("Yes");
    }
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
    /*printf("2000 2000");
    For(a,2000){
        printf("\n");
        For(n,2000){
            if((n+a)%2==0){
                printf(".");
            }
            else{
                printf("*");
            }
        }
    }*/
    return 0;
}