#include <bits/stdc++.h>
using namespace std;

int q;
int n;
int cnt[2];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        cnt[0] = cnt[1] = 0;
        vector <int> seq;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < s.length(); j++)
                cnt[s[j] - '0']++;
            seq.push_back(int(s.length()));
        }
        sort(seq.begin(), seq.end());
        int res = 0;
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] % 2)
                if (cnt[0] % 2) cnt[0]--;
                else if (cnt[1] % 2) cnt[1]--;
                else if (cnt[0] > 0) cnt[0]--;
                else if (cnt[1] > 0) cnt[1]--;
                else break;
            int tk = seq[i] / 2;
            while (tk > 0)
                if (cnt[0] >= 2) { cnt[0] -= 2; tk--; }
                else if (cnt[1] >= 2) { cnt[1] -= 2; tk--; }
                else break;
            if (tk) break;
            res++;
        }
        printf("%d\n", res);
    }
    return 0;
}