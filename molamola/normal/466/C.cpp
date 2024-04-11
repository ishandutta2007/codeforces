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

ll a[500050];

int main()
{
//  freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)scanf("%lld",a+i);
    for(i=1;i<n;i++)a[i] += a[i-1];
    if(a[n-1] % 3 != 0){printf("0");return 0;}
    ll s = a[n-1] / 3, ans = 0, c = 0;
    for(i=0;i<n-1;i++){
        if(a[i] == s+s)ans += c;
        if(a[i] == s)c++;
    }
    printf("%lld",ans);
    return 0;
}