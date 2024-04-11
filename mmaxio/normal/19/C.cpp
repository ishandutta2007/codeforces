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
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

map<int,int> prev;
int next[100000];
int len[100000], n, x[100001];
vector<int> match[100001];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    REP(i,n) next[i] = -1;
    REP(i,n) {
        scanf("%d",&x[i]);
        if (prev.find(x[i])!=prev.end()) {
            next[prev[x[i]]] = i;
        }
        prev[x[i]] = i;
    }
    FORP(i,n-1,0)
        len[i] = (next[i]==-1?1:len[next[i]]+1);
    REP(i,n)
        for (int j = next[i]; j!=-1 ; j = next[j]) match[j-i].pb(i);
    
    /*FORD(i,1,n-1) {
        cerr << i << ": ";
        REP(j,sz(match[i])) cerr << match[i][j] << ' ';
        cerr << '\n';
    }*/
    
    
    int bord = 0;
    FORD(i,1,n-1) {
        //cerr << i << ' ' << j << ' ' << sz(match[i]) << '\n';
        for (int j = lower_bound(all(match[i]),bord)-match[i].begin(), cnt;j<sz(match[i]);j++) {
            if (match[i][j]>bord && j!=0 && match[i][j]==match[i][j-1]+1) cnt++; else cnt = 1;
            if (cnt>=i) {
                bord = match[i][j]+1;
            }
        }
    }
    printf("%d\n",n-bord);
    FORD(i,bord,n-1) printf("%d ",x[i]);
}