#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

int yy[]={-1, 0, 1, 0}, xx[]={0, 1, 0, -1};
int N, M, sy, sx, ey, ex;
bool V[501][501];
char A[501][502];

int main()
{
    cin >> N >> M;
    for (int i=1;i<=N;i++) cin >> (A[i]+1);
    cin >> sy >> sx >> ey >> ex;
    queue <int> que;
    que.push(sy); que.push(sx);
    V[sy][sx] = 1;
    while (!que.empty()){
        int y = que.front(); que.pop();
        int x = que.front(); que.pop();
        for (int i=0;i<4;i++){
            int ty = y+yy[i], tx = x+xx[i];
            if (ty < 1 || ty > N || tx < 1 || tx > M || A[ty][tx] != '.' || V[ty][tx]) continue;
            V[ty][tx] = 1;
            que.push(ty), que.push(tx);
        }
    }
    int blank = 0, connected = 0;
    for (int i=0;i<4;i++){
        int y = ey+yy[i], x = ex+xx[i];
        if (y < 1 || y > N || x < 1 || x > M) continue;
        if (A[y][x] == '.' || y == sy && x == sx) blank++;
        if (V[y][x]) connected++;
    }
    bool ans = (A[ey][ex] == 'X' ? connected : (connected && blank > 1));
    cout << (ans ? "YES" : "NO") << endl;
}