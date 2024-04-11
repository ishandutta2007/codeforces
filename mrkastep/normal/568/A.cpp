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

int pal(int n){
    int t=1,d=0;
    while(t<=n){
        t*=10;
        d++;
    }
    t/=10;
    d--;
    while(n>0){
        if(n%10!=n/t) return 0;
        n%=t;
        n/=10;
        t/=100;
    }
    return 1;
}

int prime[1200000],pl[1200000];
double ans[1200000];

void solve(int n){
    int m;
    scanf("%d",&m);
    For(i,1200000){
        prime[i]=1;
    }
    prime[1]=prime[0]=0;
    FOR(i,2,1200000){
        if(prime[i]==1){
            for(int j=2;i*j<1200000;j++){
                prime[i*j]=0;
            }
        }
    }
    FOR(i,1,1200000){
        pl[i]=pal(i);
    }
    ans[0]=0;
    int a=0,b=0;
    FOR(i,1,1200000){
        a+=prime[i];
        b+=pl[i];
        ans[i]=(double)a/b;
    }
    int mx=1;
    FOR(i,1,1200000){
        if(ans[i]<=(double)n/m) mx=i;
    }
    printf("%d",mx);




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
    scanf("%d",&n); solve(n);
    return 0;
}