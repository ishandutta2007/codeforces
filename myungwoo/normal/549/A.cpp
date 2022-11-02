#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v) (v).begin(), (v).end()

int N, M;
char A[51][52];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;i++) scanf("%s", A[i]+1);
    int ans = 0;
    for (int i=1;i<N;i++) for (int j=1;j<M;j++){
        string s;
        for (int a=0;a<2;a++) for (int b=0;b<2;b++)
            s.pb(A[i+a][j+b]);
        sort(all(s));
        if (s == "acef") ans++;
    }
    printf("%d\n", ans);
}