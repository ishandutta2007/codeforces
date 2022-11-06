#include <iostream>
using namespace std;

int main()
{
    int n,k,l,m,i[100000],kusk=0,rask=0,z;
    cin>>n>>k;
    for (l=0;l<k;l++)
    {
        cin>>m;
        for (z=0;z<m;z++)
        cin>>i[z];
        z=1;
        if (i[0]==1)
            while (i[z]==i[z-1]+1) z++;
        kusk+=m-z+1;
        rask+=m-z;
    }
    cout<<kusk+rask-1;
    return 0;
}