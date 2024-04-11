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

const int MX=600;
int n, m;
int a[MX][MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    RE(j,n) RE(i,m) cin>>a[i][j];
    REV(i,1,m-1)
        REV(j,1,n-1)
            if(a[i][j] == 0)
                a[i][j] = min(a[i+1][j], a[i][j+1])-1;
    bool possible=1;
    RE(i,m)
        RE(j,n-1)
            if(a[i][j] >= a[i][j+1])
                possible = 0;
    RE(i,m-1)
        RE(j,n)
            if(a[i][j] >= a[i+1][j])
                possible = 0;
    if(!possible) {
        cout<<-1<<endl;
    } else {
        int sm=0;
        RE(i,m) RE(j,n) sm += a[i][j];
        cout<<sm<<endl;
    }
}