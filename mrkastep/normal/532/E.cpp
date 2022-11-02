#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

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

void solve(ll n){
    string s,t,tmp="";
    char c[100100];
    gets(c);
    gets(c);
    s=c;
    gets(c);
    t=c;
    int pos=0;
    int i=0;
    while(s[i]==t[i]) i++;
    pos=i;
    For(j,pos){
        tmp.pb(s[j]);
    }
    tmp.pb(t[pos]);
    for(i=pos;i<n;i++){
        tmp.pb(s[i]);
    }
    bool ok=true,good=true;
    i=0;
    int p=0;
    while(1){
        if(p>=t.size()) break;
        if(tmp[i]!=t[p]){
            if(!ok){
                good=false;
                break;
            }
            ok=false;
            i++;
            continue;
        }
        i++;
        p++;
    }
    int ans=0;
    if(good) ans++;
    tmp="";
    For(j,pos){
        tmp.pb(t[j]);
    }
    tmp.pb(s[pos]);
    for(i=pos;i<n;i++){
        tmp.pb(t[i]);
    }
    ok=true,good=true;
    i=0;
    p=0;
    while(1){
        if(p>=s.size()) break;
        if(tmp[i]!=s[p]){
            if(!ok){
                good=false;
                break;
            }
            ok=false;
            i++;
            continue;
        }
        i++;
        p++;
    }
    if(good) ans++;
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
    while(scanf("%I64d",&a)==1) solve(a);

    return 0;
}