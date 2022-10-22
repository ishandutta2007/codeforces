#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n == 3) {
            printf("3 2 1\n");
            printf("1 3 2\n");
            printf("3 1 2\n");
        } else
            for (int i = 0; i < n; i++) {
                vector <int> seq;
                for (int j = i; j > 0; j--)
                    seq.push_back(j);
                for (int j = n; j > i; j--)
                    seq.push_back(j);
                for (int j = 0; j < seq.size(); j++)
                    printf("%d%c", seq[j], j + 1 < seq.size()? ' ': '\n');
            }
    }
    return 0;
}