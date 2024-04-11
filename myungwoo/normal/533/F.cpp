#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N, M;
char A[MAXN], B[MAXN], S[MAXN], P[MAXN];
int res[MAXN][26], cnt[MAXN], arr[MAXN];
int ff[MAXN];

void kmp()
{
    for (int i=2,k=0;i<=M;i++){
        while (k && P[k+1] != P[i]) k = ff[k];
        if (P[k+1] == P[i]) k++;
        ff[i] = k;
    }
    for (int i=1,k=0;i<=N;i++){
        arr[i] = 0;
        while (k && P[k+1] != S[i]) k = ff[k];
        if (P[k+1] == S[i]) k++;
        if (k == M) k = ff[k], arr[i] = 1;
    }
}

int main()
{
    scanf("%d%d%s%s", &N, &M, A+1, B+1);
    for (int i='a';i<='z';i++) for (int j=i;j<='z';j++){
        for (int k=1;k<=N;k++) cnt[k] = 0;
        for (int k=1;k<=N;k++) S[k] = (A[k] == i) + '0';
        for (int k=1;k<=M;k++) P[k] = (B[k] == j) + '0';
        kmp();
        for (int k=M;k<=N;k++) if (arr[k]) cnt[k-M+1]++;

        for (int k=1;k<=N;k++) S[k] = (A[k] == j) + '0';
        for (int k=1;k<=M;k++) P[k] = (B[k] == i) + '0';
        kmp();
        for (int k=M;k<=N;k++) if (arr[k]) cnt[k-M+1]++;
        for (int k=1;k<=N;k++) if (cnt[k] == 2) res[k][i-'a'] = res[k][j-'a'] = 1;
    }
    vector <int> ans;
    for (int i=1;i<=N;i++){
        int sum = 0;
        for (int j=0;j<26;j++) sum += res[i][j];
        if (sum == 26) ans.push_back(i);
    }
    printf("%u\n", ans.size());
    for (int p: ans) printf("%d ", p); puts("");
}