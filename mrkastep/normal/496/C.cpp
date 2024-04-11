#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

const int mod=1e9+7;

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifdef HOME
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vector<string> t;
    string s;
    char c[111];
    int i,j,n,m,ans=0;
    bool st[111],type[111];
    scanf("%d%d",&n,&m);
    gets(c);
    For(i,n){
        gets(c);
        s=c;
        t.pb(s);
    }
    For(i,111) st[i]=type[i]=true;
    For(i,m){
        For(j,n-1){
            if(st[j]){
                if(t[j][i]>t[j+1][i]){
                    type[i]=false;
                    ans++;
                    break;
                }
            }
        }
        if(j==n-1)
            For(j,n-1)
                if(t[j][i]<t[j+1][i])
                    st[j]=false;
    }
    printf("%d",ans);








}