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
    string s,t;
    int ans=0;
    char c[1111];
    gets(c);
    gets(c);
    s=c;
    gets(c);
    t=c;
    For(i,n){
        ans+=min(abs(s[i]-t[i]),10-abs(s[i]-t[i]));
    }
    printf("%d",ans);


}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[111];
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}