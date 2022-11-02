#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>

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

struct p{
    int a,b,n;
};

bool srt(p a,p b){
    if(a.a/1000!=b.a/1000) return a.a<b.a;
    return a.b<b.b;
}

bool srt1(p a,p b){
    return a.a<b.a;
}

void solve(int n){
    vector<p> v;
    p a;
    For(i,n){
        scanf("%d%d",&a.a,&a.b);
        a.n=i+1;
        v.pb(a);
    }
    sort(all(v),srt);
    bool rv=false;
    For(i,n){
        int l=i,r=i;
        while(r<n&&v[l].a/1000==v[r].a/1000){
            r++;
            i++;
        }
        i--;
        if(rv) {
            reverse(v.begin()+l,v.begin()+r);
            rv=false;
        }
        else rv=true;
    }
    rv=false;
    For(i,n){
        int l=i,r=i;
        while(r<n&&v[l].a/1000==v[r].a/1000&&v[l].b==v[r].b){
            r++;
            i++;
        }
        i--;
        sort(v.begin()+l,v.begin()+r,srt1);
        if(rv) {
            reverse(v.begin()+l,v.begin()+r);
            rv=false;
        }
        else rv=true;
    }
    For(i,n){
        printf("%d ",v[i].n);
    }



}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    string s;
    while(scanf("%d",&n)==1) solve(n);



    return 0;
}