#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
char str[Maxn];
deque <int> seq;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        seq.clear();
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && str[i] == str[j]) j++;
            seq.push_back(j - i);
        }
        int res = 0;
        int pnt = 0;
        while (!seq.empty()) {
            res++;
            if (pnt < 0) pnt = 0;
            while (pnt + 1 < seq.size() && seq[pnt] == 1) pnt++;
            if (pnt < seq.size()) seq[pnt]--;
            if (seq[pnt] == 0) {
                seq.pop_back();
                pnt--;
            }
            if (!seq.empty()) {
                seq.pop_front();
                pnt--;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}