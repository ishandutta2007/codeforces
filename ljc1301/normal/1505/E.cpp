#include <bits/stdc++.h>
using namespace std;
char ma[100][100];
int n,m;
int main()
{
    int i,j,k,l,ans=0,minx,miny;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%s",ma[i]);
    for(i=j=0,ans+=ma[i][j]=='*';i<n-1 || j<m-1;ans+=ma[i][j]=='*')
        if(i==n-1) j++;
        else if(j==m-1) i++;
        else
        {
            minx=n,miny=m;
            for(k=i;k<n;k++)
                for(l=(k==i)+j;l<m;l++)
                    if(ma[k][l]=='*' && k+l<minx+miny)
                        minx=k,miny=l;
            if(miny==j) i++;
            else j++;
        }
    printf("%d\n",ans);
    return 0;
}