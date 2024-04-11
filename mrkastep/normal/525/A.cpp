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





char c[200200];


void solve(int n){
    vector<int> key(n),door(n);
    map<int,int> m;
    int ans=0;
    string s;
    gets(c);
    gets(c);
    s=c;
    For(i,n-1){
        key[i]=(s[i*2]-'a');
        door[i]=(s[i*2+1]-'A');
    }
    For(i,n-1){
        m[key[i]]++;
        if(m[door[i]]>0){
            m[door[i]]--;
        }
        else{
            ans++;
        }
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