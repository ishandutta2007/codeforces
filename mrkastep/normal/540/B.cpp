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

void solve(int n){
    int k,p,a,b,c,s=0,less=0;
    scanf("%d%d%d%d",&k,&p,&a,&b);
    For(i,k){
        scanf("%d",&c);
        s+=c;
        if(c<b) less++;
    }
    if(less>=(n+1)/2){
        printf("-1");
        return;
    }
    vector<int> ans;
    int rem=n-k;
    For(i,min(rem,(n-1)/2-less)){
        s+=1;
        ans.pb(1);
        k++;
    }
    For(i,n-k){
        s+=b;
        ans.pb(b);
    }
    if(s>a){
        printf("-1");
        return;
    }
    For(i,ans.size()){
        printf("%d ",ans[i]);
    }
}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}