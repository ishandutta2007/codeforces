#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <math.h>

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
int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

typedef pair<double,double> point;

vector<vector<int>> prod(vector<vector<int>> a,vector<vector<int>> b){
    vector<vector<int>> ans(2,vector<int> (b[0].size(),0));
    For(i,2){
        For(j,b[0].size()){
            For(r,2){
                ans[i][j]+=(ll)a[i][r]*b[r][j]%mod;
                ans[i][j]%=mod;
            }
        }
    }
    return ans;
}

vector<vector<int>> deg(vector<vector<int>> a,ll d){
    vector<vector<int>> ans=a;
    int s=0;
    ll one=1;
    while((one<<s)<=d) s++;
    s--;
    bool g=false;
    while(s>=0){
        if(g&&(d&(one<<s))){
            ans=prod(ans,a);
        }
        g=true;
        if(s!=0) ans=prod(ans,ans);
        s--;
    }
    return ans;
}

vector<int> deg2;

int dd(int a,ll d){
    int ans=1;
    ll one=1;
    For(i,64){
        if(d&(one<<i)){
            ans=(ll)ans*deg2[i]%mod;
        }
    }
    return ans;
}





void solve(ll n){
    ll k;
    int l;
    scanf("%I64d%d%d",&k,&l,&mod);
    vector<vector<int>> a,b,d;
    vector<int> c;
    c.pb(1);
    c.pb(1);
    a.pb(c);
    c.back()--;
    a.pb(c);
    c.clear();
    c.pb(1);
    b.pb(c);
    c[0]=1;
    b.pb(c);
    ll one=1;
    int s=0;
    while((one<<s)<=k) s++;
    s--;
    if(s>=l){
        printf("0");
        return;
    }
    d=deg(a,n);
    int t=prod(d,b)[0][0];
    deg2.pb(2);
    For(i,65){
        deg2.pb((ll)deg2.back()*deg2.back()%mod);
    }
    int ans=1,ddd=dd(2,n);
    if(l==0){
        if(k==0){
            printf("%d",1%mod);
        }
        else{
            printf("0");
        }
        return;
    }
    For(i,l){
        if(!(k&(one<<i))){
            ans=(ll)ans*t%mod;
        }
        else{
            ans=(ll)ans*(ll)(ddd-t+mod)%mod;
        }
    }
    printf("%d",ans);

}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    string s;
    char c[100100];
    ll a;
    while(scanf("%I64d",&a)==1){
        solve(a);
        printf("\n");
    }






    return 0;
}