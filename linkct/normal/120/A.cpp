#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char s[10];
    int a;
    scanf("%s%d",s,&a);
    if (s[0] == 'f')
        if (a == 1)
            printf("L\n");
        else
            printf("R\n");
    else
        if (a == 1)
            printf("R\n");
        else
            printf("L\n");
    return 0;
}