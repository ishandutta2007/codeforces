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
    char c[111];
    string s;
    map<char,int> m;
    vector<int> v;
    gets(c);
    gets(c);
    s=c;
    For(i,s.size()){
        m[s[i]]++;
    }
    if(m.size()<n){
        printf("NO");
        return;
    }
    m.clear();
    printf("YES");
    int am=0;
    For(i,s.size()){
        if(am<n&&m[s[i]]==0){
            m[s[i]]=1;
            printf("\n");
            am++;
        }
        printf("%c",s[i]);
    }


}




char c[1001000];

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