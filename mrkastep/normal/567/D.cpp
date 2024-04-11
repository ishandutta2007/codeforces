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

typedef pair<double,double> point;

int e[1001000];

bool nxt(){
    char c;
    while((c=getchar())!='-'&&c!='+');
    return c=='+';
}

int st[200200];

void solve(int n){
    int k,a,m,c;
    map<int,int> s;
    map<int,int>::iterator it;
    scanf("%d%d%d",&k,&a,&m);
    int sm=(n+1)/(a+1);
    s[0]=1;
    s[n+1]=1;
    int ans=INF;
    For(i,m){
        scanf("%d",&c);
        s[c]=1;
        it=s.find(c);
        int c1,c2;
        c1=next(it)->x-c;
        c2=c-prev(it)->x;
        sm-=(c1+c2)/(a+1);
        sm+=c1/(a+1);
        sm+=c2/(a+1);
        if(sm<k){
            ans=min(ans,i+1);
        }
    }
    if(ans==INF) ans=-1;
    printf("%d",ans);

}

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    char c[5555];
    int n;
    while(scanf("%d",&n)==1) solve(n);
    return 0;
}