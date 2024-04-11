#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL
int n,k;
bool has[100];
int x;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=1;j<=k;j++){
            scanf("%d",&x);
            if(x)
            sum += (1<<(j-1));
        }
        has[sum] = true;
    }
    for(int i=0;i<(1<<k);i++){
        for(int j=0;j<(1<<k);j++){
            if(has[i] && has[j] && ((i & j )==0))
                return !printf("YES\n");
        }
    }
    printf("NO\n");
}