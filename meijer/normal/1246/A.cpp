#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=1e5;
ll n, p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>p;
    RE(i,63) {
        ll u = n - p*i;
        if(u < 0) {
            cout<<-1<<endl;
            return 0;
        }
        ll mnCnt=0;
        RE(j,63)
            if((u & (1LL<<j)) != 0)
                mnCnt++;
        ll mxCnt=u;
        if(mnCnt <= i && mxCnt >= i) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}