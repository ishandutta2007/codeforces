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

void solve(int n){
    int m;
    scanf("%d",&m);
    vector<int> w;
    For(i,m){
        int t=-1,mx=-1,a;
        For(j,n){
            scanf("%d",&a);
            if(a>mx){
                mx=a;
                t=j;
            }
        }
        w.pb(t);
    }
    vector<int> a(n,0);
    For(i,m){
        a[w[i]]++;
    }
    int t=-1,mx=-1;
    For(i,n){
        if(a[i]>mx){
            mx=a[i];
            t=i;
        }
    }
    printf("%d",t+1);

}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    string s;
    while(scanf("%d",&n)==1) solve(n);



    return 0;
}