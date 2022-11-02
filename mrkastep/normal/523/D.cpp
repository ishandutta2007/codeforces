#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <time.h>
#include <string>
#include <algorithm>
#include <queue>

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

char c1[1001000];

void solve(int n){
    int i,s,a,t;
    ll T;
    multimap<ll,int> m;
    vector<ll> ans(n,0);
    queue<pair<int,int>> q;
    scanf("%d",&s);
    For(i,n){
        scanf("%d%d",&a,&t);
        q.push(mp(a,t));
    }
    T=q.front().x;
    while(!q.empty()||!m.empty()){
        while(m.begin()!=m.end()&&m.begin()->x==T){
            s++;
            ans[m.begin()->y]=m.begin()->x;
            m.erase(m.begin());
        }
        while(!q.empty()&&q.front().x<=T&&s>0){
            m.insert(mp(T+q.front().y,n-q.size()));
            q.pop();
            s--;
            
        }
        if(s==0){
            T=m.begin()->x;
        }
        else{
            if(m.empty()&&q.empty()) continue;
            if(q.empty()){
                T=m.begin()->x;
                continue;
            }
            if(m.empty()){
                T=q.front().x;
                continue;
            }
            T=min((ll)q.front().x,m.begin()->x);

        }
    }
    For(i,n){
        printf("%I64d\n",ans[i]);
    }



#ifdef HOME
    printf("\n\nTime in ms: %.0lf\n",clock()/CLOCKS_PER_SEC*1000);
#endif
}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[200200];
    string s;
    while(scanf("%d",&n)==1) solve(n);

    return 0;
}