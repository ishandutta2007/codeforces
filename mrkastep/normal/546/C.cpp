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

typedef pair<int,int> point;
map<pair<queue<int>,queue<int>>,int> m;


void solve(int n){
    queue<int> d1,d2;
    int a,k,b,f=0;
    scanf("%d",&k);
    For(i,k){
        scanf("%d",&a);
        d1.push(a);
    }
    scanf("%d",&k);
    For(i,k){
        scanf("%d",&a);
        d2.push(a);
    }
    while(!d1.empty()&&!d2.empty()){
        f++;
        a=d1.front();
        b=d2.front();
        d1.pop();
        d2.pop();
        if(a>b){
            d1.push(b);
            d1.push(a);
        }
        else{
            d2.push(a);
            d2.push(b);
        }
        if(m[mp(d1,d2)]>0){
            printf("-1");
            return;
        }
        m[mp(d1,d2)]++;
    }
    printf("%d %d",f,d1.empty()?2:1);




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