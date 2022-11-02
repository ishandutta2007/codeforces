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

void solve(string s){
    int i=0;
    string t;
    vector<string> v;
    if(s.back()=='.'){
        printf("NO");
        return;
    }
    while(i<s.size()){
        t="";
        while(i<s.size()&&s[i]!='.'){
            t.pb(s[i]);
            i++;
        }
        v.pb(t);
        i++;
    }
    if(v.size()<2){
        printf("NO");
        return;
    }
    if(v[0].size()<=0||v[0].size()>8){
        printf("NO");
        return;
    }
    if(v.back().size()<=0||v.back().size()>3){
        printf("NO");
        return;
    }
    FOR(j,1,v.size()-1){
        if(v[j].size()<2||v[j].size()>11){
            printf("NO");
            return;
        }
    }
    printf("YES\n");
    printf("%s",v[0].c_str());
    FOR(i,1,v.size()){
        printf(".");
        int j;
        for(j=0;j<min((size_t)3,v[i].size()-(int)(i!=v.size()-1));j++){
            printf("%c",v[i][j]);
        }
        printf("\n");
        for(;j<v[i].size();j++) printf("%c",v[i][j]);
    }
}

char c[400400];

int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n,k;
    ll a;
    string s;
    while(gets(c)) solve(s=c);


    return 0;
}