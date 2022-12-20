#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+52,LIM=22;
int n,a[nmax];
int there[1<<LIM];
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
scanf("%i",&a[i]);
there[a[i]]=a[i];
}
there[0]=-1;
for(int i=1;i<(1<<LIM);i++)
{
    if(there[i]==0)
    {
        there[i]=-1;
        for(int j=0;j<LIM;j++)
            if((i&(1<<j)))
            {
            there[i]=there[i^(1<<j)];
            if(there[i]!=-1)break;
            }
    }
//cout<<i<<" -> "<<there[i]<<endl;
}
for(int i=1;i<=n;i++)
    printf("%i ",there[(1<<LIM)-1-a[i]]);
return 0;
}