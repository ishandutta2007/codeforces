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
#include <complex>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

typedef long long int ll;

const int INF=1e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;
const double PI=3.1415926535897932384626433832795;

struct expre{
    string s;
};

expre t;

expre e(int a){
    expre ans;
    if(a>9) ans.s+='0'+a/10;
    ans.s+='0'+a%10;
    return ans;
}

expre operator+(expre &a,expre &b){
    expre ans;
    ans.s='('+a.s+'+'+b.s+')';
    return ans;
}

expre operator-(expre &a,expre &b){
    expre ans;
    ans.s='('+a.s+'-'+b.s+')';
    return ans;
}

expre operator*(expre &a,expre &b){
    expre ans;
    ans.s='('+a.s+'*'+b.s+')';
    return ans;
}

expre abs(expre &a){
    expre ans;
    ans.s="abs("+a.s+')';
    return ans;
}

expre f(int a){
    expre p=t-e(a);
    return (abs(abs(p)-e(1)))-(abs(p)-e(1));
}



void solve(){
    t.s="t";
    int n,a,b,c;
    expre ans1,ans2;
    ans1.s=ans2.s="0";
    scanf("%d",&n);
    For(i,n){
        scanf("%d%d%d",&a,&b,&c);
        expre tmp=f(i)*e(b/2);
        ans2=ans2+tmp;
        tmp=f(i)*e(a/2);
        ans1=ans1+tmp;
    }
    printf("%s\n",ans1.s.c_str());
    printf("%s",ans2.s.c_str());
    //printf("%d",(abs((abs((17-17))-1))-(abs((17-17))-1)));
}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    srand(time(NULL));
    solve();
    return 0;
}