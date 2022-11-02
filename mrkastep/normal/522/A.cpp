#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e9;
const double eps=1e-9;

bool letter(char c){
    return c<='Z'&&c>='A'||c<='z'&&c>='a'||c>='0'&&c<='9';
}

string getword(){
    string s;
    char c;
    while(!letter(c=getchar()));
    if(c<='Z') c+=32;
    s.pb(c);
    while(letter(c=getchar())){
        if(c<='Z') c+=32;
        s.pb(c);
    }
    return s;
}

void solve(int n){
    map<string,int> m;
    string s;
    int i,ans=1;
    m["polycarp"]=1;
    For(i,n){
        s=getword();
        getword();
        m[s]=m[getword()]+1;
        ans=max(ans,m[s]);
    }
    printf("%d",ans);







}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#else
    if(0){
        freopen("expedition.in","rt",stdin);
        freopen("expedition.out","wt",stdout);
    }
#endif
    int n,i;
    ll a;
    char c[300];
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}