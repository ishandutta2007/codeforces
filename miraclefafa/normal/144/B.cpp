#include <cstdio>
#include <algorithm>
using namespace std;
int x1,x2,y1,y2,n,i,j,k,x[1020],y[1020],r[1020],ans;
bool flag;
int main() {
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d%d%d",&x[i],&y[i],&r[i]);
    for (i=min(x1,x2);i<=max(x1,x2);i++) for (j=min(y1,y2);j<=max(y1,y2);j++) 
    if (i==min(x1,x2) || i==max(x1,x2) || j==min(y1,y2) || j==max(y1,y2)) {
        for (k=0,flag=1;k<n;k++) if ((x[k]-i)*(x[k]-i)+(y[k]-j)*(y[k]-j)<=r[k]*r[k]) {
            flag=0;break;
        }
        ans+=flag;
    }
    printf("%d",ans);
}