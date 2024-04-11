#include<cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for(int i=n+1;;i++) {
        int j=i;
        int a=j%10;
        j=j/10;
        int b=j%10;
        j=j/10;
        int c=j%10;
        j=j/10;
        int d=j%10;
        if(a!=b&&b!=c&&c!=d&&b!=d&&a!=d&&a!=c)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}