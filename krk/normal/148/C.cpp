#include <cstdio>
using namespace std;

int n, a, b;

int main()
{
    scanf("%d %d %d", &n, &a, &b);
    int prv;
    if (b) {
           printf("1"); prv = 1;
           for (int i = 0; i < b; i++) printf(" %d", prv = 2 * prv);
           for (int i = 0; i < a; i++) printf(" %d", ++prv);
           int lft = n - 1 - a - b;
           while (lft--) printf(" 1");
           printf("\n");
    } else if (a)
              if (n >= a + 2) {
                    int lft = n - a;
                    printf("1"); lft--;
                    while (lft--) printf(" 1");
                    prv = 1;
                    for (int i = 0; i < a; i++) printf(" %d", ++prv);
                    printf("\n");
              } else printf("-1\n");
    else for (int i = 0; i < n; i++) printf("1%c", i + 1 < n? ' ': '\n');
    return 0;
}