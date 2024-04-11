#include <stdio.h>
#include <vector>
using namespace std;

#define MAXN 200005
typedef long long lld;

int N; lld S1[MAXN],S2[MAXN];
char A[MAXN],B[MAXN];
lld Q; double ans;
vector <int> C[26],D[26];

int main()
{
    int i,j,k,n,m;
    scanf("%d%s%s",&N,A+1,B+1);
    for (i=1;i<=N;i++){
        Q += lld(N-i+1)*(N-i+1);
        C[A[i]-'A'].push_back(i);
        D[B[i]-'A'].push_back(i);
    }
    for (i=0;i<26;i++){
        n = C[i].size();
        m = D[i].size();
        for (j=0;j<=n;j++) S1[j] = 0;
        for (j=0;j<=m;j++) S2[j] = 0;
        for (j=n;j--;) S1[j] = S1[j+1]+(N-C[i][j]+1);
        for (j=m;j--;) S2[j] = S2[j+1]+(N-D[i][j]+1);
        for (j=k=0;j<n&&k<m;j++){
            while (k < m && D[i][k] < C[i][j]) k++;
            ans += double(C[i][j]*S2[k])/Q;
        }
        for (j=k=0;j<m&&k<n;j++){
            while (k < n && C[i][k] <= D[i][j]) k++;
            ans += double(D[i][j]*S1[k])/Q;
        }
    }
    printf("%.9lf",ans);
}