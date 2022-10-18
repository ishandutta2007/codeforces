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
#include <algorithm>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

vector<pair<int,int> > pos, neg;
int nPos, nNeg;

bool ok(lf x) {
    int uk = nNeg-1;
    lf left = 1e21;
    FORP(i,nPos-1,0) {
        while (uk>=0 && neg[uk].fs>=pos[i].fs) {
            left = min(left,neg[uk].fs+neg[uk].sc*x);
            uk--;
        }
        if (pos[i].fs+pos[i].sc*x>=left) return 1;
    }
    return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n, x, v;
    
    scanf("%d",&n);
    
    REP(i,n) {
        scanf("%d%d",&x,&v);
        if (v>0) pos.pb(mp(x,v)); else neg.pb(mp(x,v));
    }
    
    nPos = sz(pos), nNeg = sz(neg);
    
    if (nPos==0 || nNeg==0) {puts("-1"); return 0;}
    
    sort(all(pos)), sort(all(neg));
    
    if (pos[0].fs>neg.back().fs) {puts("-1"); return 0;}
    
    lf l = 0, r = 2000000000.0;
    
    REP(i,100) {
        lf m = (l+r)/2;
        if (ok(m)) r = m; else l = m;
    }
    
    printf("%.12lf",l);
}