#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

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
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;

int e[1001000];

bool nxt(){
    char c;
    while((c=getchar())!='-'&&c!='+');
    return c=='+';
}



void solve(int n){
    map<int,ll> one,two,three;
    int a,k;
    scanf("%d",&k);
    For(i,n){
        scanf("%d",&a);
        if(a%k==0){
            three[a]+=two[a/k];
            two[a]+=one[a/k];
        }
        one[a]++;
    }
    ll ans=0;
    for(map<int,ll>::iterator it=three.begin();it!=three.end();it++){
        ans+=it->y;
    }
    printf("%I64d",ans);


}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    char c[5555];
    int n;
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}