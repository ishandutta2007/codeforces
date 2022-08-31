#include <cstdio>
#include <cmath>
using namespace std;
int n,i,x,fg;
double y;
int main() {
    scanf("%d",&n);fg=0;
    for (i=1;i*(i+1)/2<n;i++) {
        x=n-i*(i+1)/2;y=((sqrt(x*8.+1)-1)/2);
        if (abs(y-(int)y)<=1e-8) { fg=1;break;
        }
    }
    if (fg) puts("YES"); else puts("NO");
}