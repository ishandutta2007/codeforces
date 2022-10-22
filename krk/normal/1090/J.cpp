#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 37;
const int arg2 = 1000007;
const int Maxn = 100005;

int pw1[Maxn], pw2[Maxn];
char A[Maxn], B[Maxn];
int alen, blen;
ii HA[Maxn], HB[Maxn];
int mya[Maxn], myb[Maxn];
int seq[Maxn];
ll res;

void makeHash(char A[], int alen, ii HA[])
{
    ii cur = ii(0, 0);
    for (int i = 1; i <= alen; i++) {
        cur.first = (ll(cur.first) * arg1 + ll(A[i] - 'a' + 1)) % mod1;
        cur.second = (ll(cur.second) * arg2 + ll(A[i] - 'a' + 1)) % mod2;
        HA[i] = cur;
    }
}

ii getHash(ii H[], int l, int r)
{
    ii res = H[r];
    l--;
    if (l >= 0) {
        res.first = (ll(res.first) - ll(pw1[r - l]) * H[l].first % mod1 + mod1) % mod1;
        res.second = (ll(res.second) - ll(pw2[r - l]) * H[l].second % mod2 + mod2) % mod2;
    }
    return res;
}

int getSame(int a, int b)
{
    if (a > b) swap(a, b);
    int tk = a;
    int tk2 = mya[a + 1];
    int res = tk + tk2;
    if (res >= b) res = b + myb[1 + b - a];
    return res;
}

bool Less(const int &a, const int &b)
{
    int sam = getSame(a, b);
    int lena = a + blen, lenb = b + blen;
    if (sam == lenb) return false;
    if (sam == lena) return true;
    char ach = sam < a? A[1 + sam]: B[1 + sam - a];
    char bch = sam < b? A[1 + sam]: B[1 + sam - b];
    return ach < bch;
}

int main()
{
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%s", A + 1); alen = strlen(A + 1);
    scanf("%s", B + 1); blen = strlen(B + 1);
    makeHash(A, alen, HA);
    makeHash(B, blen, HB);
    for (int i = 1; i <= alen; i++) {
        int lef = 0, rig = min(alen + 1 - i, blen);
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (getHash(HA, i, i + mid - 1) == getHash(HB, 1, mid))
                lef = mid + 1;
            else rig = mid - 1;
        }
        mya[i] = lef - 1;
    }
    for (int i = 1; i <= blen; i++) {
        int lef = 0, rig = blen + 1 - i;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (getHash(HB, i, i + mid - 1) == getHash(HB, 1, mid))
                lef = mid + 1;
            else rig = mid - 1;
        }
        myb[i] = lef - 1;
    }
    for (int i = 0; i < alen; i++)
        seq[i] = i + 1;
    sort(seq, seq + alen, Less);
    for (int i = 0; i < alen; i++) {
        res += seq[i] + blen;
        if (i > 0) res -= getSame(seq[i - 1], seq[i]);
    }
    res--;
    int cur = 0;
    for (int i = 2; i <= alen; i++) {
        cur = max(cur, mya[i]);
        if (cur == 0) res--;
        cur = max(cur - 1, 0);
    }
    cout << res << endl;
    return 0;
}