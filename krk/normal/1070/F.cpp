#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 400005;

int n;
int A[Maxn], B[Maxn], C[Maxn], D[Maxn];
int alen, blen, clen, dlen;
ll res;

bool Less(const int &a, const int &b)
{
    return a > b;
}

void Fix(int A[], int alen)
{
    sort(A + 1, A + alen + 1, Less);
    for (int i = 1; i <= alen; i++)
        A[i] += A[i - 1];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char tmp[5]; scanf("%s", tmp);
        int num; scanf("%d", &num);
        if (tmp[0] == '1' && tmp[1] == '1') A[++alen] = num;
        else if (tmp[0] == '1' && tmp[1] == '0') B[++blen] = num;
        else if (tmp[0] == '0' && tmp[1] == '1') C[++clen] = num;
        else D[++dlen] = num;
    }
    Fix(A, alen); Fix(B, blen); Fix(C, clen); Fix(D, dlen);
    for (int i = 0; i <= dlen && i <= alen; i++) {
        ll cand = ll(A[alen]) + ll(D[i]);
        int x = alen - i;
        int mn = min(blen, clen);
        int tk = min(blen, mn + x); cand += B[tk];
        tk = min(clen, mn + x); cand += C[tk];
        res = max(res, cand);
    }
    printf("%I64d\n", res);
    return 0;
}