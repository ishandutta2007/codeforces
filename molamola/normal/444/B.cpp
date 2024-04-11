#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

ll x;
int a[100010], b[100010], c[100010];
int n, d;

ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int p[100010];

int main()
{
    scanf("%d%d%lld",&n,&d,&x);
    int i, j;
    initAB();
    if(d < 1000){
        for(i=0;i<n;i++){
            if(b[i] == 0)continue;
            for(j=0;j<n-i;j++)c[i+j] = max(c[i+j], a[j]);
        }
    }
    else{
        for(i=0;i<n;i++)p[a[i]] = i;
        set <int> S;
        for(i=0;i<n;i++){
            S.insert(-a[i]);
            for(set <int>::iterator it = S.begin();it != S.end();++it){
                if(b[i-p[-*it]]){
                    c[i] = -*it;
                    break;
                }
            }
        }
    }
    for(i=0;i<n;i++)printf("%d\n",c[i]);
    return 0;
}