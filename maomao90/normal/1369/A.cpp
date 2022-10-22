#include <cstdio>
 
using namespace std;
 
int t, n;
 
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n % 4 == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}