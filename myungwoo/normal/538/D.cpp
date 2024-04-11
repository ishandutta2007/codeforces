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

int N;
char A[51][52], B[102][102];
bool chk[51][51];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%s", A[i]+1);
    vector <pii> pos;
    for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) if (A[i][j] == 'o') pos.pb(mp(i, j));
    for (int i=1;i<N+N;i++) for (int j=1;j<N+N;j++) B[i][j] = '.';
    for (int dy=-N+1;dy<N;dy++){
        for (int dx=-N+1;dx<N;dx++) if (dy || dx){
            bool valid = 1;
            for (auto &p: pos){
                int y = p.first + dy, x = p.second + dx;
                if (y < 1 || y > N || x < 1 || x > N) continue;
                if (A[y][x] == '.'){ valid = 0; break; }
            }
            if (!valid) continue;
            B[dy+N][dx+N] = 'x';
            for (auto &p: pos){
                int y = p.first + dy, x = p.second + dx;
                if (y < 1 || y > N || x < 1 || x > N) continue;
                chk[y][x] = 1;
            }
        }
    }
    bool ans = 1;
    for (int i=1;i<=N&&ans;i++) for (int j=1;j<=N&&ans;j++) if (A[i][j] == 'x' && !chk[i][j]) ans = 0;
    if (!ans){ puts("NO"); return 0; }
    puts("YES");
    B[N][N] = 'o';
    for (int i=1;i<N+N;i++) puts(B[i]+1);
}