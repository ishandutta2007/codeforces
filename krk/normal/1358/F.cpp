#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int lim = 200000;
const int Maxm = 4000000;

int n;
vector <ll> A;
vector <ll> B;
char res[Maxm];
int rlen;

vector <ll> Reverse(const vector <ll> &V)
{
    vector <ll> res = V;
    reverse(res.begin(), res.end());
    return res;
}

ll Count2()
{
    ll a = B[0], b = B[1];
    ll res = 0;
    while (true) {
        if (a > b) swap(a, b);
        if (a == 0) return -1;
        if (a == A[0])
            if (b < A[1]) return -1;
            else if ((b - A[1]) % a) return -1;
            else {
                res += (b - A[1]) / a;
                return res;
            }
        if (a == A[1])
            if (b < A[0]) return -1;
            else if ((b - A[0]) % a) return -1;
            else {
                res += (b - A[0]) / a;
                return res;
            }
        res += b / a;
        b %= a;
    }
    return -1ll;
}

bool getPrefix(vector <ll> &B)
{
    for (int i = int(B.size()) - 1; i > 0; i--) {
        B[i] -= B[i - 1];
        if (B[i] <= 0) return false;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    A.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &A[i]);
    B.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &B[i]);
    if (n == 1) {
        if (A[0] == B[0]) {
            printf("SMALL\n");
            printf("0\n");
        } else printf("IMPOSSIBLE\n");
        return 0;
    }
    if (n == 2) {
        ll res = Count2();
        if (res > lim) {
            printf("BIG\n");
            printf("%I64d\n", res);
            return 0;
        }
        if (res == -1) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    while (true) {
        if (A == B) break;
        auto revB = Reverse(B);
        if (A == revB) {
            res[rlen++] = 'R';
            break;
        }
        if (B[0] > B[1]) {
            res[rlen++] = 'R';
            B = revB;
        }
        if (getPrefix(B)) res[rlen++] = 'P';
        else {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    int cnt = 0;
    for (int i = 0; i < rlen; i++)
        cnt += res[i] == 'P';
    if (cnt > lim) {
        printf("BIG\n");
        printf("%d\n", cnt);
        return 0;
    }
    reverse(res, res + rlen);
    res[rlen] = '\0';
    printf("SMALL\n");
    printf("%d\n", rlen);
    printf("%s\n", res);
    return 0;
}