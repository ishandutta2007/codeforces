#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define ll long long int
#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second

const int mod=1e9+7;
const int INF=2e9;
const ll LONGINF=4e18;

char ff(string &s){
    For(i,s.size()){
        if(s[i]!=' ') return s[i];
    }
    return '0';
}


char c[(1<<20)+10];


void solve(string &s){
    vector<string> t,ans;
    t.pb(s);
    while(gets(c)){
        t.pb(s=c);
    }
    For(i,t.size()){
        s.clear();
        if(ff(t[i])!='#'){
            For(j,t[i].size()){
                if(t[i][j]!=' ') s.pb(t[i][j]);
            }
        }
        else{
            s=t[i];
        }
        if(ans.empty()||ff(t[i])=='#'||ff(ans.back())=='#'){
            ans.pb(s);
            continue;
        }
        ans.back()+=s;
    }
    For(i,ans.size()){
        printf("%s\n",ans[i].c_str());
    }







    
}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    string s;
    while(gets(c)){
        solve(s=c);
    }




    return 0;
}