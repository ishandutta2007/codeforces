#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

typedef pair<int,int> point;
typedef long long int ll;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;







void solve(string &s){
    vector<int> t(s.size(),0);
    int a,m,sm=0,n=s.size();
    scanf("%d",&m);
    For(i,m){
        scanf("%d",&a);
        a--;
        t[a]=1-t[a];
        if(a>0) t[n-a]=1-t[n-a];
    }
    For(i,n){
        sm+=t[i];
        sm%=2;
        if(sm%2==0){
            printf("%c",s[i]);
        }
        else{
            printf("%c",s[s.size()-i-1]);
        }
    }



}

char c[200200];

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n,k;
    ll a;
    string s;
    if(gets(c)) solve(s=c);



    return 0;
}