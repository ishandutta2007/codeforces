#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    bool u=false;
    char t;
    int an=a.size(),bn=b.size(),cn=c.size(),k,l=an/bn,ia[30],ib[30],ic[30],kol=0,z,q,y,kol1=0,kol2=0;
    for (k=0;k<30;k++)
    {
        ia[k]=0;
        ib[k]=0;
        ic[k]=0;
    }
    for (k=0;k<an;k++)
    ia[a[k]-97]++;
    for (k=0;k<bn;k++)
    ib[b[k]-97]++;
    for (k=0;k<cn;k++)
    ic[c[k]-97]++;
    for (k=0;k<=l&&u==false;k++)
    {
        z=k;
        q=2e9;
        for (y=0;y<30;y++) if (ic[y]!=0) q=min(q,ia[y]/ic[y]);
        z+=q;
        if (z>kol) {kol=z;kol1=k;kol2=q;}
        for (y=0;y<30;y++)
        {
            ia[y]-=ib[y];
            if (ia[y]<0) u=true;
        }
    }
    for (k=0;k<30;k++)
    ia[k]=0;
    for (k=0;k<an;k++)
    ia[a[k]-97]++;
    for (;kol1>0;kol1--)
    {
        cout<<b;
        for (y=0;y<30;y++)
        ia[y]-=ib[y];
    }
    for (;kol2>0;kol2--)
    {
        cout<<c;
        for (y=0;y<30;y++)
        ia[y]-=ic[y];
    }
    for (y=0;y<30;y++)
    for (;ia[y]>0;ia[y]--)
    {
        t=y+97;
        cout<<t;
    }
    return 0;
}