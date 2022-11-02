#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(v) (v).begin(),(v).end()

typedef pair<int,int> point;
typedef long long int ll;

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e18;
const double eps=1e-9;

bool getword(string &s){
    s.clear();
    char c;
    while(!isalpha(c=getchar())&&c!=EOF);
    if(c==EOF) return false;
    s.pb(c);
    while(isalpha(c=getchar())) s.pb(c);
    return true;
}


void solve(int n){
    map<string,int> m;
    string s;
    vector<int> v,t;
    int a,ans=0;
    scanf("%d",&a);
    For(i,n){
        scanf("%d",&a);
        v.pb(a);
    }
    sort(all(v));
    while(getword(s))
        m[s]++;
    for(auto p=m.begin();p!=m.end();p++){
        t.pb(p->y);
    }
    sort(all(t));
    For(i,t.size()){
        ans+=t[i]*v[t.size()-i-1];
    }
    printf("%d ",ans);
    ans=0;
    For(i,t.size()){
        ans+=t[i]*v[v.size()-t.size()+i];
    }
    printf("%d",ans);
}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n,k;
    ll a;
    string s;
    if(scanf("%d",&n)==1) solve(n);


    return 0;
}