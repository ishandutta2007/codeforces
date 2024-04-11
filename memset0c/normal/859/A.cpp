#include<bits/stdc++.h>
using namespace std;
int n, a, maxa;
int main() {
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&a);
        maxa = max(maxa, a);
    }
    printf("%d", max(maxa - 25, 0));
    return 0;
}