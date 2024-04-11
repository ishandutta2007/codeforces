#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char q[30005][25];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%s",q[i]);
    int l=strlen(q[0]);

    for (int i=0;i<n;i++)
        for (int j=0;j<l;j++)
            if (q[i][j]!=q[0][j])
                l=j;
    printf("%d",l);

    return 0;
}