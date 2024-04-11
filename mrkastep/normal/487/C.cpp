#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define ll long long int
#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second

const int mod=1e9+7;
const int INF=2e9;
const ll LONGINF=4e18;

pair<int,int> euclid(int a,int b){
    if(b>a){
        pair<int,int> p1;
        p1=euclid(b,a);
        return mp(p1.y,p1.x);
    }
    if(b==0){
        return mp(1,0);
    }
    int c=a%b;
    pair<int,int> p=euclid(b,c);
    return mp(p.y,p.x-p.y*(a/b));
}

int obr[100100],fct[100100],obrfct[100100];

void sep(int a,map<int,int> &ans){
    int i;
    FOR(i,2,(int)sqrt((double)a)+1){
        while(a%i==0){
            ans[i]++;
            a/=i;
        }
    }
    if(a!=1) ans[a]++;
}

int cnk(int n,int k){
    return (ll)fct[n]*obrfct[k]%mod*obrfct[n-k]%mod;
}

bool prime1(int a){
    int i;
    FOR(i,2,sqrt((double)a)){
        if(a%i==0) return false;
    }
    return true;
}

bool prime(int a){
    int i;
    FOR(i,2,(int)sqrt((double)a)+1){
        if(a%i==0) return false;
    }
    return true;
}

void solve(int n){
    int i;
    if(n==4){
        printf("YES\n1\n3\n2\n4");
        return;
    }
    if(!prime(n)){
        printf("NO");
        return;
    }
    obr[1]=1;
    FOR(i,2,n+1){
        obr[i]=((ll)n*n-(ll)(n/i)*obr[n%i])%n;
    }
    printf("YES\n");
    printf("%d\n",1);
    FOR(i,2,n+1){
        printf("%I64d\n",((ll)i*obr[i-1]-1)%n+1);
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
    char c[100100];
    string s;
    while(scanf("%d",&n)==1){
        solve(n);
    }




    return 0;
}