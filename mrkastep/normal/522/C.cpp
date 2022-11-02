#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define ll long long int

const int INF=2e9;
const int mod=1e9+7;
const ll LONGINF=4e9;
const double eps=1e-9;

void solve(){
    int m,n,a[100100],j,unk=0,b,t,i,mini=INF,p[100100],q[100100];
    bool g=false;
    vector<bool> stt(100100,true);
    vector<char> st;
    vector<int> psb;
    scanf("%d%d",&m,&n);
    st.assign(n+1,'N');
    a[0]=INF;
    For(i,n){
        scanf("%d",&a[i+1]);
    }
    For(i,m-1){
    scanf("%d%d",&p[i],&q[i]);
    if(q[i]==1) g=true;
    if(g) stt[p[i]]=false;
    }
    g=true;
    For(i,m-1){
        if(g&&(q[i]==1)){
            For(j,n+1){
                if((unk>=a[j])&&stt[j]){
                    if(j!=p[i]) psb.pb(j);
                    mini=min(a[j],mini);
                }
            }
            g=false;
        }
        if(p[i]==0){
            unk++;
        }
        a[p[i]]--;
    }
    if(g){
        mini=0;
    }
    for(i=n;i>0;i--){
        if(!psb.empty()&&psb.back()==i){
            st[i]='Y';
            psb.pop_back();
        }
        if(a[i]<=unk-mini){
            st[i]='Y';
        }
    }
    FOR(i,1,n+1){
        printf("%c",st[i]);
    }
    printf("\n");
}






int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#else
    if(0){
        freopen("expedition.in","rt",stdin);
        freopen("expedition.out","wt",stdout);
    }
#endif
    int n,i;
    ll a;
    char c[300];
    string s;
    scanf("%d",&n);
    For(i,n){
        solve();
    }

    return 0;
}