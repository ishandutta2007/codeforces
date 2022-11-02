#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <math.h>
#include <cmath>
#include <complex>
#include <unordered_map>
#include <stack>
#include <set>

#pragma warning(disable:4996)

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define x first
#define y second

typedef long long int ll;
typedef vector<ll> lll;
typedef complex<double> point;
//typedef pair<double,double> point;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

char c[2222];

vector<int> pi(string &s){
    vector<int> pif;
    pif.assign(s.size(),0);
    FOR(i,1,s.size()){
        int j=pif[i-1];
        while(j>0&&s[i]!=s[j]){
            j=pif[j-1];
        }
        if(s[i]==s[j]) j++;
        pif[i]=j;
    }
    return pif;
}

string s,t;

vector<int> a,b;

void solve(){
    gets(c);
    s=c;
    gets(c);
    t=c;
    vector<pair<int,int>> ans;
    while(!t.empty()){
        a=pi(t+'#'+s);
        reverse(all(s));
        b=pi(t+'#'+s);
        reverse(all(s));
        int ta=0,tb=0,tai,tbi;
        FOR(i,t.size(),a.size()){
            if(a[i]>ta){
                ta=a[i];
                tai=i-t.size();
            }
            if(b[i]>tb){
                tb=b[i];
                tbi=i-t.size();
            }
        }
        if(ta==0&&tb==0){
            printf("-1");
            return;
        }
        if(ta>tb){
            ans.pb(mp(tai-ta+1,tai));
        }
        else{
            ans.pb(mp(s.size()-tbi+1+tb-1,s.size()-tbi+1));
        }
        reverse(all(t));
        For(i,max(ta,tb)) t.pop_back();
        reverse(all(t));
    }
    printf("%d\n",ans.size());
    For(i,ans.size()){
        printf("%d %d\n",ans[i].x,ans[i].y);
    }

}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    //#else
    //  freopen("a.in","rt",stdin);
    //  freopen("a.out","wt",stdout);
#endif
    solve();
    return 0;
}