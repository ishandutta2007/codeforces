#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
const int INF = 2e9;
const int mx = 1e5;

struct C{
    int a,b;
    C(){};
    C(int a,int b):a(a),b(b){};
    bool operator < (const C &X) const{
        return a<X.a;
    }
};
int n,A[2010],S,k;
int main()
{
    scanf("%d",&n);
    printf("%d\n",n+1);
    for(int i=1; i<=n; i++) scanf("%d",&A[i]);
    for(int i=n; i>=1; i--)
    {
        k = (i - A[i] - S)%(n+1);
        k = (k+n+1)%(n+1);
        S += k;
        printf("1 %d %d\n",i,k);
    }
    printf("2 %d %d",n,n+1);
}