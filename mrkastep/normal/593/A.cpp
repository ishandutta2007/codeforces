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

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

typedef long long int ll;

const int INF=1e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

string word(){
    string s;
    char c;
    while(!isalpha(c=getchar()));
    s+=c;
    while(isalpha(c=getchar())) s+=c;
    return s;
}

vector<string> v;

void solve(){
    int n;
    scanf("%d",&n);
    For(i,n) v.pb(word());
    int ans=0;
    For(a,26){
        For(b,a){
            int t=0;
            For(i,n){
                bool g=true;
                For(j,v[i].size()){
                    if(v[i][j]-'a'!=a&&v[i][j]-'a'!=b) g=false;
                }
                if(g) t+=v[i].size();
            }
            ans=max(ans,t);
        }
    }
    printf("%d",ans);





}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    srand(time(NULL));
    solve();
    return 0;
}