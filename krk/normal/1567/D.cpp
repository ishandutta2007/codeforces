#include <bits/stdc++.h>
using namespace std;

int T;
int s, n;
multiset <int> S;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &s, &n);
        S.clear();
        int pw = 1;
        while (s > 0) {
            while (s % 10) {
                S.insert(pw);
                s--;
            }
            s /= 10;
            pw *= 10;
        }
        vector <int> seq;
        while (seq.size() + S.size() < n) {
            auto it = S.begin();
            if (*it >= 10) {
                for (int i = 0; i < 10; i++)
                    S.insert(*it / 10);
                S.erase(it);
            } else {
                seq.push_back(*it);
                S.erase(it);
            }
        }
        for (auto it: S)
            seq.push_back(it);
        for (int i = 0; i < n - 1; i++)
            printf("%d ", seq[i]);
        int sum = 0;
        for (int i = n - 1; i < seq.size(); i++)
            sum += seq[i];
        printf("%d\n", sum);
    }
    return 0;
}