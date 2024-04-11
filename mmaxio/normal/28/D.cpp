#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

map<int,int> last;
int next[100000];
bool use[100000];
vector<int> ans;
int v[100000], c[100000], l[100000], r[100000];
pair<int,int> can[300001];
int from_can[300001];
int from_truck[100001];
int best = -1;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    REP(i,n) {
        scanf("%d%d%d%d",&v[i],&c[i],&l[i],&r[i]);
        int eqv = c[i] + l[i] + r[i];
        if (last.find(eqv)!=last.end()) next[last[eqv]] = i;
        next[i] = -1; last[eqv] = i;
    }

    //cerr << v[54] << ' ' << c[54] << ' ' << l[54] << ' ' << r[54] << '\n';
    //cerr << v[82] << ' ' << c[82] << ' ' << l[82] << ' ' << r[82] << '\n';


    clean(use);
    REP(i,300001) can[i].sc = -1;
    REP(kk,n) {
        if (!use[kk]) {
            int eqv = l[kk] + r[kk] + c[kk];
            can[0] = mp(0,kk);
            from_can[0] = -1;
            //cerr << eqv << " - ";
            for (int i = kk; i != -1; i = next[i]) {
                //cerr << i << ' ';
                use[i] = 1;
                if (can[l[i]].sc==kk)
                    if (can[ l[i] + c[i] ].sc!=kk || can[l[i]+c[i]].fs<can[l[i]].fs+v[i]) {
                        can[ l[i] + c[i] ] = mp(can[l[i]].fs+v[i],kk);
                        from_can[ l[i] + c[i] ] = i;
                        from_truck[i]  = from_can[l[i]];
                    }               
            }
            if (can[eqv].sc==kk && can[eqv].fs>best) {
                ans.clear();
                for (int i = from_can[eqv]; i != -1; i = from_truck[i]) ans.pb(i);
                best = can[eqv].fs;
            }
        }
    }
    reverse(all(ans));
    printf("%d\n",sz(ans));
    REP(i,sz(ans)) printf("%d ",ans[i]+1);
    //REP(i,sz(ans)-1) if (ans[i]>ans[i+1]) return 1; 
}