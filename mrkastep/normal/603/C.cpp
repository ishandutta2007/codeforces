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

#pragma warning(disable:4996)

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

typedef long long int ll;
typedef vector<ll> lll;

const int INF=1e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

int k;

int F(int a){
    if(k==0){
        switch(a){
        case 0: return 0;
        case 1: return 1;
        case 2: return 2;
        case 3: return 0;
        default: return 1^(a%2);
        }
    }
    switch(a){
    case 0: return 0;
    case 1: return 1;
    case 2: return 0;
    case 3: return 1;
    case 4: return 2;
    case 5: return 0;
    default: 
        if(a%2==0) return F(a/2)==1?2:1;
        else return 0;
    }
}

void solve(){
    int n,a,ans=0;
    scanf("%d%d",&n,&k);
    k%=2;
    For(i,n){
        scanf("%d",&a);
        ans^=F(a);
    }
    if(ans==0){
        printf("Nicky");
    }
    else{
        printf("Kevin");
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