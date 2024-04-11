#include <iostream>

using namespace std;

int main()
{
    int a,i[2200][2],k,t,ma,me=1,kol;
    cin>>a;
    for (k=0;k<a;k++)
    {cin>>i[k][0];i[k][1]=0;}
    for (k=0;k<a;k++)
    {
        ma=0;
        kol=0;
        for (t=0;t<a;t++)
        if (i[t][0]>ma&&i[t][1]==0) ma=i[t][0];
        for (t=0;t<a;t++)
        if (i[t][0]==ma) {i[t][1]=me;kol++;}
        me+=kol;
    }
    for (k=0;k<a;k++) cout<<i[k][1]<<' ';
    return 0;
}