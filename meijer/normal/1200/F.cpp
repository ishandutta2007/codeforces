#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=2000;
const int DIF=2520;

int n, q, x, y;
int k[MX], m[MX], e[MX][10];
int mem[MX][DIF];
bitset<DIF> visited[MX];

int N(int a) {
    if(a > 0) return a%DIF;
    return (a+1260000000)%DIF;
}
int countCycle(int bx, int by) {
    set<int> cnt;
    int x=bx, y = N(by);
    cnt.insert(x);
    while(true) {
        int nextY = N(y + k[x]);
        int nextX = e[x][nextY%m[x]];
        x = nextX; y = nextY;
        cnt.insert(x);
        if(x == bx && y == by) break;
    }
    return cnt.size();
}
int getAns(int x, int y) {
    y = N(y);
    if(mem[x][y] == -1) {
        visited[x][y] = 1;
        int nextY = N(y + k[x]);
        int nextX = e[x][nextY%m[x]];
        if(visited[nextX][nextY] && mem[nextX][nextY] == -1)
            mem[x][y] = countCycle (nextX,nextY);
        else
            mem[x][y] = getAns     (nextX,nextY);
    }
    return mem[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n) cin>>k[i];
    REP(i,0,n) {
        cin>>m[i];
        REP(j,0,m[i])
            cin>>e[i][j], e[i][j]--;
    }
    REP(i,0,n)
        REP(j,0,DIF)
            mem[i][j] = -1;
    REP(i,0,n) visited[i].reset();
    cin>>q;
    while(q--) {
        cin>>x>>y; x--;
        cout<<getAns(x,y)<<endl;
    }
}