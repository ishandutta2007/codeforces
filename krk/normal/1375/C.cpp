#include <bits/stdc++.h>
using namespace std;

int T;
int n;
vector <int> seq;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        seq.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            while (seq.size() > 1 && seq[int(seq.size()) - 2] < a) seq.pop_back();
            if (seq.empty() || seq.back() > a) seq.push_back(a);
        }
        printf("%s\n", seq.size() == 1? "YES": "NO");
    }
    return 0;
}