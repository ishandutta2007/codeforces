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
typedef pair<int,int> pii;
typedef long long lld;

int N,M,K,X,Y,Z,ans;
int pi[101];
int D[101][101][101],from[101][101][101];
char A[102],B[102],C[102];
string S;

int main()
{
    int i,j,k;
    scanf("%s%s%s",A+1,B+1,C+1);
    N = strlen(A+1), M = strlen(B+1), K = strlen(C+1);
    for (i=2,k=0;i<=K;i++){
        while (k && C[k+1] != C[i]) k = pi[k];
        if (C[k+1] == C[i]) k++;
        pi[i] = k;
    }
    for (i=0;i<=N;i++) for (j=0;j<=M;j++) for (k=0;k<=K;k++) D[i][j][k] = -1e9;
    D[0][0][0] = 0;
    for (i=0;i<=N;i++) for (j=0;j<=M;j++) for (k=0;k<K;k++) if (D[i][j][k] >= 0){
        if (ans < D[i][j][k]){
            ans = D[i][j][k];
            X = i, Y = j, Z = k;
        }
        if (i < N && D[i+1][j][k] < D[i][j][k]) D[i+1][j][k] = D[i][j][k], from[i+1][j][k] = -1;
        if (j < M && D[i][j+1][k] < D[i][j][k]) D[i][j+1][k] = D[i][j][k], from[i][j+1][k] = -2;
        if (i < N && j < M && A[i+1] == B[j+1]){
            int nxtk = k;
            while (nxtk && C[nxtk+1] != A[i+1]) nxtk = pi[nxtk];
            if (C[nxtk+1] == A[i+1]) nxtk++;
            if (nxtk == K) continue;
            if (D[i+1][j+1][nxtk] < D[i][j][k]+1)
                D[i+1][j+1][nxtk] = D[i][j][k]+1, from[i+1][j+1][nxtk] = k;
        }
    }
    while (X || Y || Z){
        if (from[X][Y][Z] == -1) X--;
        else if (from[X][Y][Z] == -2) Y--;
        else{
            S.pb(A[X]);
            int nxt = from[X][Y][Z];
            X--, Y--, Z = nxt;
        }
    }
    reverse(all(S));
    if (S.empty()) puts("0");
    else puts(S.c_str());
}