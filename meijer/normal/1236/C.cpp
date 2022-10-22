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

const int MX=300*305;
int n;
vi ans[300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int j=0; int dir=1;
    RE(i,n*n) {
        ans[j].pb(i+1);
        j += dir;
        if(j == n)
            dir = -1, j+=dir;
        if(j == -1)
            dir = 1, j+=dir;
    }
    RE(i,n) {
        RE(j,n) cout<<(j==0?"":" ")<<ans[i][j];
        cout<<endl;
    }
}