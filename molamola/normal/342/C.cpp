/*
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

int p[8];

int main()
{
//  freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int i,x;
    for(i=0;i<n;i++){scanf("%d",&x);p[x]++;}
    if(p[5]||p[7]){printf("-1");return 0;}
    int c=p[3],a=p[4];
    n/=3;
    if(n!=p[1] || n-a!=p[6] || n-c!=p[2]){printf("-1");return 0;}
    for(i=0;i<a;i++)printf("1 2 4\n");
    for(i=0;i<n-a-c;i++)printf("1 2 6\n");
    for(i=0;i<c;i++)printf("1 3 6\n");
    return 0;
}
*/


#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

int r,h;
int ans;
double r3=sqrt(3);

int main()
{
//  freopen("input.txt","r",stdin);
    scanf("%d%d",&r,&h);
    int t = h/r;
    h-=r*t;
    ans=2*t+1;
    if(h*2>=r)ans=max(ans,2*t+2);
    if((double)h>r3*r/2.0)ans=max(ans,2*t+3);
    printf("%d",ans);
    return 0;
}