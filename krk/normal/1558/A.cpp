#include <bits/stdc++.h>
using namespace std;

int T;
int a, b;

int main()
{
    scanf("%d", &T);
    while (T--) {
        vector <int> seq;
        scanf("%d %d", &a, &b);
        int A = (a + b + 1) / 2;
        int B = (a + b) / 2;
        for (int x = 0; x <= a && x <= A; x++) if (A - x <= b) {
            int k = A - x + a - x;
            seq.push_back(k); 
        }
        for (int x = 0; x <= b && x <= A; x++) if (A - x <= a) {
            int k = A - x + b - x;
            seq.push_back(k);
        }
        sort(seq.begin(), seq.end());
        seq.erase(unique(seq.begin(), seq.end()), seq.end());
        printf("%d\n", int(seq.size()));
        for (int i = 0; i < seq.size(); i++)
            printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    }
    return 0;
}