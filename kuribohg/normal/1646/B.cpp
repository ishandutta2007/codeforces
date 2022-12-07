#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;
const int MAXN=1000010;
int T, n;
LL a[MAXN], presum[MAXN], sufsum[MAXN];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) presum[i]=presum[i-1]+a[i],sufsum[i]=sufsum[i-1]+a[n+1-i];
        bool ok=false;
        for(int i=1;i<=n;i++) {
            if(i+i-1<=n) {
                LL sumred = sufsum[i-1];
                LL sumblue = presum[i];
                if(sumred>sumblue) ok=true;
            }
        }
        if(ok) puts("YES"); else puts("NO");
    }

    return 0;
}