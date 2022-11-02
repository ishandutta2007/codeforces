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
#include <cmath>
#include <complex>
#include <unordered_map>
#include <stack>
#include <set>

#pragma warning(disable:4996)

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define x first
#define y second

typedef long long int ll;
typedef vector<ll> lll;
typedef complex<double> point;
//typedef pair<double,double> point;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

int a[111][111],st[111];

void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    For(i,m) st[i]=0;
    For(i,n){
        int k,a;
        scanf("%d",&k);
        For(j,k){
            scanf("%d",&a);
            st[a-1]=1;
        }
    }
    For(i,m){
        if(st[i]==0){
            printf("NO");
            return;
        }
    }
    printf("YES"); 
}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    //#else
    //  freopen("a.in","rt",stdin);
    //  freopen("a.out","wt",stdout);
#endif
    solve();
    return 0;
}