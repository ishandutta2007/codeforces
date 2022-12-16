#include<cstdio>
#include<cmath>
using namespace std;
struct point
{
    int x,y;
    friend int operator *(point A,point B){return A.x*B.y-A.y*B.x;}
    friend point operator -(point A,point B){point C;C.x=A.x-B.x;C.y=A.y-B.y;return C;}
}p[3100];
int ans,n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    for(int i=1;i<=n-2;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<=n;k++)
                if((p[i]-p[j])*(p[j]-p[k]))ans++;
                    printf("%d",ans);
    return 0;
}