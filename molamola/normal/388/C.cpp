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

int inp[110][110];
int L[110];
int ans[2];
int arr[110];

int main()
{
    int n;
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",L+i);
        for(j=1;j<=L[i];j++)scanf("%d",inp[i]+j);
        int tmp = L[i]>>1;
        for(j=1;j<=tmp;j++)ans[0] += inp[i][j], ans[1] += inp[i][L[i]-j+1];
    }
    int now = 0;
    for(i=1;i<=n;i++){
        if(L[i]%2){
            arr[now++] = inp[i][L[i]/2+1];
        }
    }
    sort(arr,arr+now);
    reverse(arr,arr+now);
    for(i=0;i<now;i++){
        if(i&1)ans[1] += arr[i];
        else ans[0] += arr[i];
    }
    printf("%d %d",ans[0],ans[1]);
    return 0;
}