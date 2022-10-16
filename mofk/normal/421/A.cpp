#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, a, b, c[105]={0}, d;
    scanf("%d%d%d", &n, &a, &b);
    for(int i=0; i<a; i++) scanf("%d", &d), c[d-1]=1;
    for(int i=0; i<b; i++) {scanf("%d", &d); if(c[d-1]!=1) c[d-1]=2;}
    for(int i=0; i<n; i++) printf("%d ", c[i]);
    return 0;
}