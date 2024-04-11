#include <stdio.h>
#include <algorithm>
using namespace std;

int n,d; long long x;
int a[100001],b[100001],c[100001],r[100001],s[100001];
int pr[100002],nx[100002];

long long  getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

int main()
{
    scanf ("%d %d %lld",&n,&d,&x);

    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for (int i=0;i<n;i++) r[a[i]] = i;
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
    
    if (d < 3000){
        for (int i=0,j=0;i<n;i++) if (b[i]) s[j++] = i;

        for (int j=1;j<=n;j++){
            int x = r[j];
            for (int k=0;k<d&&x+s[k]<n;k++) c[x+s[k]] = j;
        }
    }
    else{
        for (int l=0;l<n;l++){
            for (int j=n;j>=1;j--){
                int x = r[j];
                if (x <= l && b[l-x]){
                    c[l] = j; break;
                }
            }
        }
    }

    for (int i=0;i<n;i++) printf ("%d\n",c[i]);

    return 0;
}