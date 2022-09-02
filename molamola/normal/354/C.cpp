#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

int a[1000010];
int s=0x7fffffff,h;

int main()
{
    int n,i,k;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[max(0,x-k)]++;
        a[x+1]--;
        s=min(s,x);
        h=max(x,h);
    }
    for(i=1;i<=h;i++)a[i]+=a[i-1];
    for(i=s;;i--){
        int t,c=0;
        for(t=i;t<=h;t+=i)c+=a[t];
        if(c>=n){printf("%d",i);break;}
    }
    return 0;
}