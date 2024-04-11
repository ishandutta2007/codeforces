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
#define ll long long int
#define all(v) (v).begin(),(v).end()

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;

vector<vector<pair<int,int>>> g;

int ans=0;

int deep(int v){
    int t=0,sm=0,tmp;
    For(i,g[v].size()){
        tmp=deep(g[v][i].x);
        sm+=tmp;
        sm+=g[v][i].y;
        t=max(t,tmp+g[v][i].y);
    }
    ans+=t*g[v].size()-sm;
    return t;
}

int gcd(int a,int b){
    while(a>0&&b>0){
        if(a>b){
            a%=b;
        }
        else{
            b%=a;
        }
    }
    return max(a,b);
}

vector<int> pr_f (string &s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

vector<int> z_f(string &s){
    int n=s.size(),l=0,r=0;
    vector<int> z(n,0);
    FOR(i,1,n){
        if(i<r){
            z[i]=min(z[i-l],r-i);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]>r){
            r=i+z[i];
            l=i;
        }
    }
    return z;
}

string getword(){
    string s;
    char c;
    while(!isalpha(c=getchar()));
    s.pb(c);
    while(isalpha(c=getchar())) s.pb(c);
    return s;
}

void solve(int n){
    int k;
    string s;
    vector<int> p,ans(n,0),z;
    int r=0;
    scanf("%d",&k);
    p=pr_f(s=getword());
    z=z_f(s);
    For(i,n){
        if((i+1)%(i+1-p[i])!=0) continue;
        if((i+1)/(i+1-p[i])%k!=0) continue;
        ans[i]=1;
        if(i==n-1) continue;
        int j;
        for(j=max(r-i,0);j<min(z[i+1],(i+1)/k);j++){
            ans[i+j+1]=1;
            r=max(r,i+j+1);
        }
    }
    For(i,n){
        printf("%d",ans[i]);
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
    char c[100100];
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}