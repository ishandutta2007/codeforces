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

int R[100010],L[100010],inp[100010];
int n,l,r,ql,qr,ans=0x7fffffff;

int main()
{
    scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr);
    int i;
    for(i=1;i<=n;i++)scanf("%d",inp+i);
    for(i=1;i<=n;i++)L[i]=L[i-1]+inp[i]*l;
    for(i=n;i;i--)R[i]=R[i+1]+inp[i]*r;
    for(i=0;i<=n;i++){
        int a=L[i]+R[i+1];
        if(i<n/2)a+=qr*(n-2*i-1);
        if(i>n/2)a+=ql*(2*i-n-1);
        ans=min(ans,a);
    }
    printf("%d",ans);
    return 0;
}