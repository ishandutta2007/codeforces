#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
vector <int> S;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        S.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (S.empty() || S.back() < a) S.push_back(a);
            else {
                int en = S.back();
                while (!S.empty() && S.back() > a) S.pop_back();
                S.push_back(en);
            }
        }
        printf("%d\n", int(S.size()));
    }
    return 0;
}