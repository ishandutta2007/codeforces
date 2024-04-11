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
int N, M;
char A[2001][2002];

void dfs(int y, int x)
{
    if (y < 1 || x < 1 || y >= N || x >= M) return;
    int cnt = 0;
    for (int i=0;i<2;i++) for (int j=0;j<2;j++) if (A[y+i][x+j] == '*') cnt++;
    if (cnt != 1) return;
    for (int i=0;i<2;i++) for (int j=0;j<2;j++) A[y+i][x+j] = '.';
    for (int i=-1;i<2;i++) for (int j=-1;j<2;j++) dfs(y+i, x+j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i=1;i<=N;i++) cin >> A[i]+1;
    for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) dfs(i, j);
    for (int i=1;i<=N;i++) cout << A[i]+1 << endl;
}