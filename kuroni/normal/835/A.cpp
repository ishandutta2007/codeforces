#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int s, v1, v2, t1, t2;
    scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
    if (2 * t1 + s * v1 == 2 * t2 + s * v2)
        printf("Friendship");
    else if (2 * t1 + s * v1 < 2 * t2 + s * v2)
        printf("First");
    else printf("Second");
}