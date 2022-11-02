#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
 
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
 
typedef pair<int,int> point;

void solve(int n){
    int a;
    vector<int> ans;
    For(i,n){
        bool good=true;
        For(j,n){
            scanf("%d",&a);
            if(a==1||a==3) good=false;
        }
        if(good){
            ans.pb(i+1);
        }
    }
    printf("%d\n",ans.size());
    For(i,ans.size()){
        printf("%d ",ans[i]);
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
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}