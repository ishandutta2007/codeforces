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
#define ll long long int


const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.14159265359;

ll sum[5000500],sb[5000500];

void solve(int n){
    FOR(i,1,5000500){
        sum[i]=0;
        int t=i;
        FOR(j,2,(int)(sqrt((double)i))+1){
            if(i%j==0){
                sum[i]=sum[i/j]+1;
                t=0;
                break;
            }
        }
        if(t>1){
            sum[i]++;
        }
    }
    sum[0]=0;
    sb[0]=0;
    FOR(i,1,5000500){
        sb[i]=sb[i-1]+sum[i];
    }
    int a,b;
    For(i,n){
        scanf("%d%d",&a,&b);
        printf("%I64d\n",sb[a]-sb[b]);

    }










}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    ll a;
    int n;
    string s;
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}