#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#pragma comment(linker,"/STACK:33554432")

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

#define MAXN 100005

int N; lld D[MAXN][10],E[MAXN][10],ans1,ans2;
char A[MAXN];

int main()
{
    int i,j,k;
    scanf("%s",A+1); N = strlen(A+1);
    for (i=1;i<=N;i++) for (j=0;j<10;j++) D[i][j] = -1e9;
    D[1][A[1]-'0'] = (A[1] == '9'); E[1][A[1]-'0'] = 1;
    for (i=1;i<N;i++) for (j=0;j<10;j++) if (D[i][j] >= 0){
        int m = A[i+1]-'0';
        if (j+m == 9){
            if (D[i+1][9] < D[i][j]+1) D[i+1][9] = D[i][j]+1, E[i+1][9] = 0;
            if (D[i+1][9] == D[i][j]+1) E[i+1][9] += E[i][j];
        }
        if (D[i+1][m] < D[i][j]+(m==9)) D[i+1][m] = D[i][j]+(m==9), E[i+1][m] = 0;
        if (D[i+1][m] == D[i][j]+(m==9)) E[i+1][m] += E[i][j];
    }
    ans1 = -1;
    for (i=0;i<10;i++){
        if (ans1 < D[N][i]) ans1 = D[N][i], ans2 = 0;
        if (ans1 == D[N][i]) ans2 += E[N][i];
    }
    cout << ans2 << endl;
}