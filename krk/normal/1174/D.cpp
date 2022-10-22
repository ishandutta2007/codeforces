#include <bits/stdc++.h>
using namespace std;

int n, x;
vector <int> seq;
bool tk[1 << 18];

int main()
{
    scanf("%d %d", &n, &x);
    if (x >= 1 << n) {
        int lst = 0;
        for (int i = 1; i < 1 << n; i++) {
            seq.push_back(i ^ lst);
            lst = i;
        }
    } else {
        tk[0] = tk[x] = true;
        int lst = 0;
        for (int i = 0; i < 1 << n; i++) if (!tk[i]) {
            seq.push_back(i ^ lst);
            lst = i;
            tk[i] = tk[i ^ x] = true;
        }
    }
    printf("%d\n", int(seq.size()));
    for (int i = 0; i < seq.size(); i++)
        printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    return 0;
}