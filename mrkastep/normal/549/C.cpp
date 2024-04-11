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



void solve(int n){
    int k,c[2],a,h[2];
    scanf("%d",&k);
    c[0]=c[1]=0;
    For(i,n){
        scanf("%d",&a);
        c[a%2]++;
    }
    h[0]=(n-k+1)/2;
    h[1]=(n-k)/2;
    if(n==k){
        if(c[1]%2==1){
            printf("Stannis");
            return;
        }
        printf("Daenerys");
        return;
    }
    if(h[1]==h[0]){
        if(k%2==0){
            printf("Daenerys");
            return;
        }
        if(c[0]<=h[0]){
            printf("Stannis");
            return;
        }
        printf("Daenerys");
        return;
    }
    if(k%2==0){
        if(c[0]<=h[1]||c[1]<=h[1]){
            printf("Daenerys");
            return;
        }
        printf("Stannis");
        return;
    }
    if(c[1]<=h[1]){
        printf("Daenerys");
        return;
    }
    printf("Stannis");













}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    char c[111];
    string s;
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}