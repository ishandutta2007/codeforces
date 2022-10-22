#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
bool tk[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(tk, tk + n + 1, false);
        vector <int> seq;
        for (int i = 1; i <= n; i++) if (!tk[i]) {
            int num = i;
            while (num <= n) {
                tk[num] = true;
                seq.push_back(num);
                num *= 2;
            }
        }
        printf("2\n");
        for (int i = 0; i < seq.size(); i++)
            printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    }
    return 0;
}