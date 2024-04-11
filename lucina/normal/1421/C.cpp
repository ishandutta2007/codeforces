#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
char s[nax];

int main() {
    /**
    a[bar]e
    1. a[bar]e[bar']
    2. e[bar'] a[bar]e[bar']
    3. [bar]e[bar']a[bar
    */

    scanf("%s", s + 1);
    int n = strlen(s + 1);
    puts("3\nR 2");
    printf("L %d\n", n);
    printf("L %d\n", n - 1);


}