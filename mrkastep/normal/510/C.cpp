#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>

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

char c1[1001000];

vector<vector<int>> g(26);

void solve(int n){
    vector<string> t;
    vector<bool> st(26,true);
    string s,ans="";
    char c[111];
    int i,j,k;
    bool good;
    gets(c);
    For(i,n){
        gets(c);
        t.pb(s=c);
    }
    For(i,n-1){
        for(j=0;j<t[i].size()&&t[i][j]==t[i+1][j];j++);
        if(j!=t[i].size()){
            if(j==t[i+1].size()){
                printf("Impossible");
                return;
            }
            g[t[i+1][j]-'a'].pb(t[i][j]-'a');
        }
    }
    For(i,26){
        For(j,26){
            if(!st[j]) continue;
            good=true;
            For(k,g[j].size()){
                if(st[g[j][k]]){
                    good=false;
                    break;
                }
            }
            if(good){
                ans.pb(j+'a');
                st[j]=false;
                break;
            }
        }
    }
    if(ans.size()!=26){
        printf("Impossible");
        return;
    }
    printf("%s",ans.c_str());

#ifdef HOME
    printf("\n\nTime in ms: %.0lf\n",clock()/CLOCKS_PER_SEC*1000);
#endif
}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[200200];
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}