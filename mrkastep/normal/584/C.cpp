#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <math.h>

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

char c[100100];
string s1,s2,s3;

void solve(){
    int n,t,tt=0;
    scanf("%d%d",&n,&t);
    gets(c);
    gets(c);
    s1=c;
    gets(c);
    s2=c;
    vector<int> eq;
    For(i,n){
        if(s1[i]==s2[i]){
            eq.pb(i);
            tt++;
        }
    }
    if(tt<n-2*t){
        printf("-1");
        return;
    }
    For(i,n){
        For(j,3){
            if('a'+j==s1[i]||'a'+j==s2[i]) continue;
            s3.pb('a'+j);
            break;
        }
    }
    int d1=n,d2=n;
    For(i,n){
        if(d1>t){
            if(s1[i]==s2[i]){
                s3[i]=s1[i];
                d1--;
                d2--;
            }
        }
    }
    For(i,n){
        if(s3[i]==s2[i]) continue;
        if(d1>t){
            s3[i]=s1[i];
            d1--;
            continue;
        }
        if(d2>t){
            s3[i]=s2[i];
            d2--;
        }
    }
    printf("%s",s3.c_str());



}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    solve();
    return 0;
}