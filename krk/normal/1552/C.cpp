#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;

int T;
int n, k;
bool tk[Maxn];
int A[Maxn], B[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        fill(tk, tk + 2 * n, false);
        for (int i = 0; i < k; i++) {
            int a, b; scanf("%d %d", &a, &b);
            a--; b--;
            if (a > b) swap(a, b);
            A[i] = a; B[i] = b;
            tk[a] = tk[b] = true;
        }
        vector <int> seq;
        for (int i = 0; i < 2 * n; i++) if (!tk[i])
            seq.push_back(i);
        int hf = int(seq.size()) / 2;
        int sz = k;
        for (int i = 0; i < hf; i++) {
            A[sz] = seq[i];
            B[sz] = seq[hf + i];
            sz++;
        }
        int res = 0;
        for (int i = 0; i < sz; i++)
            for (int j = i + 1; j < sz; j++)
                if (A[i] < A[j]) res += A[j] < B[i] && B[i] < B[j];
                else res += A[i] < B[j] && B[j] < B[i];
        printf("%d\n", res);
    }
    return 0;
}