#include <cstdio>
 
using namespace std;
 
int w;
 
int main() {
    scanf("%d", &w);
    printf((w - 2) != 0 && (w - 2) % 2 == 0 ? "YES" : "NO");
    return 0;
}