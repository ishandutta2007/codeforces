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







void solve(int n){
    vector<int> l;
    vector<int> q;
    ll ans=0;
    int a;
    For(i,n){
        scanf("%d",&a);
        l.pb(a);
    }
    sort(all(l));
    while(l.size()>1){
        if(l.back()-l[l.size()-2]>1){
            l.pop_back();
            continue;
        }
        if(l.back()>l[l.size()-2]){
            l.back()--;
        }
        q.pb(l.back());
        l.pop_back();
        l.pop_back();
    }
    sort(all(q));
    while(q.size()>1){
        ans+=(ll)q.back()*q[q.size()-2];
        q.pop_back();
        q.pop_back();
    }
    printf("%I64d",ans);




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