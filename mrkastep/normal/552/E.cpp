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

typedef pair<double,double> point;

string s;

ll count(int l,int r){
    ll sm=0;
    if(l<0||r<0) return 0;
    FOR(i,l,r){
        ll prod=s[i];
        while(i+2<r&&s[i+1]=='*'){
            prod*=s[i+2];
            i+=2;
        }
        sm+=prod;
        i++;
    }
    return sm;
}

void solve(){
    int n=s.size();
    vector<int> z;
    ll ans=0;
    For(i,n){
        if(s[i]<='9'&&s[i]>='0') s[i]-='0';
        if(s[i]=='*') z.pb(i);
    }
    int k,l,r;
    scanf("%d",&k);
    For(i,z.size()){
        For(j,i){
            int l=z[j],r=z[i];
            int pl=l,pr=r;
            while(pl-2>0&&s[pl-2]=='*') pl-=2;
            while(pr+2<n&&s[pr+2]=='*') pr+=2;
            ans=max(ans,count(0,pl-2)+count(pl-1,l)*count(l+1,r)*count(r+1,pr+2)+count(pr+3,n));
        }
    }
    printf("%I64d",ans);

}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    string t;
    char c[5555];
    while(gets(c)){
        s="1*";
        t=c;
        s+=t;
        s+="*1";
        solve();
    }
    return 0;
}