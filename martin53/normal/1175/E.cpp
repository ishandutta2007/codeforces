#include<bits/stdc++.h>
using namespace std;
const int LIM=5e5+42;
int go[20][LIM];
void upd(int step)
{
    for(int i=1;i<LIM;i++)
        go[step][i]=max(go[step][i],go[step][i-1]);
}
int main()
{
int n,q;
scanf("%i%i",&n,&q);
int l,r;
for(int i=1;i<=n;i++)
{
    scanf("%i%i",&l,&r);
    go[0][l]=max(go[0][l],r);
}
upd(0);

for(int step=1;step<20;step++)
{
    for(int i=0;i<LIM;i++)
    {
        go[step][i]=go[step-1][go[step-1][i]];
    }
    upd(step);
}

for(int i=1;i<=q;i++)
{
    scanf("%i%i",&l,&r);
    if(go[19][l]<r)
    {
        printf("-1\n");
        continue;
    }

    int add=0;
    for(int j=19;j>=0;j--)
        if(go[j][l]<r)
        {
            add=add+(1<<j);
            l=go[j][l];
        }

    printf("%i\n",add+1);
}
return 0;
}