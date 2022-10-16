#include <iostream>

using namespace std;

const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?",
             fi0 = "What are you doing while sending \"",
             fi1 = "\"? Are you busy? Will you send \"",
             fi2 = "\"?";

constexpr int64_t ml = 2e18L;

int64_t len(int n) {
    int64_t res = f0.size();
    for (int i = 0; i < n && res < ml; ++i)
        res = fi0.size() + res + fi1.size() + res + fi2.size();
    return min(res, ml);
}

char get(const string& s, int64_t k) {
    return k < s.size()? s[k]: '.';
}

char solve(int n, int64_t k) {
    if (n == 0)
        return get(f0, k);

    if (k < fi0.size())
        return fi0[k];
    k -= fi0.size();

    if (k < len(n - 1))
        return solve(n - 1, k);
    k -= len(n - 1);

    if (k < fi1.size())
        return fi1[k];
    k -= fi1.size();

    if (k < len(n - 1))
        return solve(n - 1, k);
    k -= len(n - 1);

    return get(fi2, k);
}

int main()
{
    int64_t q, n, k;
    cin >> q;
    while (q--) {
        cin >> n >> k;
        cout << solve(n, --k);
    }
    return 0;
}