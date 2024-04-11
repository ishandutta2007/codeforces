#include <cstdio>
using namespace std;

int a1, a2, a3, a4;

int main()
{
    scanf("%d %d %d %d", &a1, &a2, &a3, &a4);
    if (a3 + 1 == a4) {
           a1 -= a4; a2 -= a4;
           if (a1 < 0 || a2 < 0) printf("-1\n");
           else {
                printf("7");
                for (int i = 0; i <= a1; i++) printf("4");
                for (int i = 2; i < a4; i++) printf("74");
                for (int i = 0; i <= a2; i++) printf("7");
                printf("4\n");
           }
    } else if (a3 == a4) {
           a1 -= a3 + 1; a2 -= a4;
           if (a1 < 0 || a2 < 0) {
                  a1 += a3 + 1; a2 += a4;
                  a1 -= a3; a2 -= a4 + 1;
                  if (a1 < 0 || a2 < 0) printf("-1\n");
                  else {
                       printf("7");
                       for (int i = 0; i < a1; i++) printf("4");
                       for (int i = 0; i < a3; i++) printf("47");
                       for (int i = 0; i < a2; i++) printf("7");
                       printf("\n");
                  }
           }
           else {
                for (int i = 0; i <= a1; i++) printf("4");
                for (int i = 1; i < a3; i++) printf("74");
                for (int i = 0; i <= a2; i++) printf("7");
                printf("4\n");
           }
    } else if (a3 == a4 + 1) {
           a1 -= a3; a2 -= a3;
           if (a1 < 0 || a2 < 0) printf("-1\n");
           else {
                for (int i = 0; i <= a1; i++) printf("4");
                printf("7");
                for (int i = 2; i <= a3; i++) printf("47");
                for (int i = 1; i <= a2; i++) printf("7");
                printf("\n");
           }
    } else printf("-1\n");
    return 0;
}