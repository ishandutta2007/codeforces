#include <iostream>

using namespace std;

int main()
{
    int n,i[1000],k,l,p=0,f=0;
    cin>>n;
    for (k=0;k<n;k++)
    cin>>i[k];
    k=0;
    while (k<n&&f==0)
    {
        p=0;
        for (l=0;l<n;l++)
        if (i[l]!=l) p=1;
        if (p==0) f=1;
        for (l=0;l<n;l++)
            if (l%2==0) i[l]=(i[l]+1)%n; else
            {
                i[l]--;
                if (i[l]<0) i[l]+=n;
            }
        k++;
    }
    if (f==1) cout<<"YES"; else cout<<"NO";
    return 0;
}