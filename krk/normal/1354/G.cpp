#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int T;
int n, k;
deque <int> all, seq;

string Check(const deque <int> &A, const deque <int> &B)
{
    int lim = min(A.size(), B.size());
    printf("? %d %d\n", lim, int(B.size()));
    for (int i = 0; i < lim; i++)
        printf("%d%c", A[i], i + 1 < A.size()? ' ': '\n');
    for (int i = 0; i < B.size(); i++)
        printf("%d%c", B[i], i + 1 < B.size()? ' ': '\n');
    fflush(stdout);
    string res; cin >> res;
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        all.resize(n);
        for (int i = 0; i < n; i++)
            all[i] = i + 1;
        seq = all;
        shuffle(seq.begin(), seq.end(), rng);
        int cur = seq[0];
        for (int i = 1; i < seq.size() && i <= 28; i++)
            if (Check({cur}, {seq[i]}) == "SECOND")
                cur = seq[i];
        all.erase(all.begin() + cur - 1);
        seq = {cur};
        while (seq.size() < all.size()) {
            deque <int> B;
            for (int i = 0; i < seq.size(); i++) {
                B.push_back(all.front());
                all.pop_front();
            }
            if (Check(seq, B) == "FIRST") {
                all = B;
                break;
            }
            for (int i = 0; i < B.size(); i++)
                seq.push_back(B[i]);
        }
        while (all.size() > 1) {
            int m = all.size() / 2;
            deque <int> B;
            for (int i = 0; i < m; i++) {
                B.push_back(all.front());
                all.pop_front();
            }
            if (Check(seq, B) == "FIRST")
                all = B;
        }
        printf("! %d\n", all.front());
        fflush(stdout);
    }
    return 0;
}