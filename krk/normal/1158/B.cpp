#include <bits/stdc++.h>
using namespace std;

vector <int> seq;
int n, k;

int main()
{
    while (scanf("%d %d", &n, &k) == 2) {
        seq.clear();
        if (n == k)
            for (int i = 0; i < n; i++)
                seq.push_back(0);
        else if (k == 1) {
            seq.push_back(0);
            for (int i = 1; i < n; i++)
                seq.push_back(1);
        } else {
            int lft = k - 2;
            if (lft + k + lft <= n) {
                for (int i = 0; i < lft; i++)
                    seq.push_back(0);
                seq.push_back(1);
                for (int i = 0; i < lft; i++)
                    seq.push_back(0);
                seq.push_back(1);
                while (seq.size() < n)
                    seq.push_back(0);
            } else {
                int each = (n - k) / 2 + 1;
                for (int i = 0; i < n; i++)
                    if (i % each == 0) seq.push_back(1);
                    else seq.push_back(0);
            }
        }
        for (int i = 0; i < seq.size(); i++)
            printf("%d", seq[i]);
        printf("\n");
    }
    return 0;
}