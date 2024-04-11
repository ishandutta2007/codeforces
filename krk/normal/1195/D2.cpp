#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxl = 11;
const int Maxn = 100005;

int n;
int a[Maxn];
vector <int> seq[Maxn];
int beg[Maxn][Maxl], A[Maxn][Maxl], B[Maxn][Maxl];
int cnt[Maxl];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        int num = a[i];
        while (num) {
            seq[i].push_back(num % 10);
            num /= 10;
        }
        reverse(seq[i].begin(), seq[i].end());
        cnt[seq[i].size()]++;
        for (int j = 0; j <= seq[i].size(); j++) {
            int cur = 0;
            for (int z = 0; z < int(seq[i].size()) - j; z++)
                cur = 10 * cur + seq[i][z];
            for (int z = 0; z < j; z++)
                cur = 100ll * ll(cur) % mod;
            beg[i][j] = cur;
            cur = 0;
            for (int z = int(seq[i].size()) - j; z < seq[i].size(); z++) {
                cur = 10ll * ll(cur) % mod;
                cur = (cur + seq[i][z]) % mod;
                cur = 10ll * ll(cur) % mod;
            }
            A[i][j] = cur;
            cur = 0;
            for (int z = int(seq[i].size()) - j; z < seq[i].size(); z++) {
                cur = 100ll * ll(cur) % mod;
                cur = (cur + seq[i][z]) % mod;
            }
            B[i][j] = cur;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= seq[i].size(); j++) {
            res = (res + ll(cnt[j]) * beg[i][j]) % mod;
            res = (res + ll(cnt[j]) * A[i][j]) % mod;
            res = (res + ll(cnt[j]) * beg[i][j]) % mod;
            res = (res + ll(cnt[j]) * B[i][j]) % mod;
        }
        for (int j = seq[i].size() + 1; j < Maxl; j++) {
            res = (res + ll(cnt[j]) * A[i][seq[i].size()]) % mod;
            res = (res + ll(cnt[j]) * B[i][seq[i].size()]) % mod;
        }
    }
    printf("%d\n", res);
    return 0;
}