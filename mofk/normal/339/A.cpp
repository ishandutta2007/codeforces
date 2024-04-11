#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int a[105], n;
    char s[105];
    scanf("%s", s);
    for(int i=0, j=0; i<strlen(s); i+=2, j++) a[j]=s[i]-48, n=j;
    n++;
    sort(a, a+n);
    for(int i=0; i<n-1; i++) printf("%d+", a[i]);
    printf("%d", a[n-1]);
    return 0;
}