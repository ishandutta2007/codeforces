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

const int MX=1e5;
int q, c, m, x;

bool possible(int a) {
    int C = c-a;
    int M = m-a;
    int X = x + C + M - a;
    if(X < 0) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    RE(i,q) {
        cin>>c>>m>>x;
        int lb=0, ub=min(c,m);
        while(lb != ub) {
            int mid=(lb+ub+1)/2;
            if(possible(mid)) lb = mid;
            else ub = mid-1;
        }
        cout<<lb<<endl;
    }
}