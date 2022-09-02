#include <stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int p[100010];
int d[100010][2];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",p+i);
    d[1][0] = 1;
    for(int i=2;i<=n;i++){
        d[i][0] = min(p[i], d[i-1][0] + 1);
    }
    d[n][1] = 1;
    for(int i=n-1;i;i--){
        d[i][1] = min(p[i], d[i+1][1] + 1);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, min(d[i][0], d[i][1]));
    }
    printf("%d",ans);
    return 0;
}