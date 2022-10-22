#include <cstring>
#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n, t;
char A[Maxn], B[Maxn];

int main()
{
    scanf("%d %d", &n, &t);
    scanf("%s", A); scanf("%s", B);
    int two = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
        if (A[i] != B[i]) one++;
        else two++;
    for (int x = 0; x <= n && 2 * x <= one && x <= t; x++) {
        int sim = t - one + x;
        if (0 <= sim && sim <= two) {
            int o1 = x, o2 = x;
            for (int i = 0; i < n; i++)
                if (A[i] != B[i])
                    if (o1) { printf("%c", B[i]); o1--; }
                    else if (o2) { printf("%c", A[i]); o2--; }
                    else {
                        char ch = 'a';
                        while (ch == A[i] || ch == B[i]) ch++;
                        printf("%c", ch);
                    }
                else if (sim) {
                        char ch = 'a';
                        while (ch == A[i]) ch++;
                        printf("%c", ch);
                        sim--;
                    } else printf("%c", A[i]);
            printf("\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}