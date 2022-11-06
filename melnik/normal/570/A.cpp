#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#define long long ll;
using namespace std;

int main()
{
    int n,m,k,l,i[105][105],z[105],num=1;
    cin>>n>>m;
    for (k=0;k<m;k++)
        for (l=1;l<=n;l++)
            cin>>i[k][l];
    for (k=0;k<m;k++)
        i[k][0]=1;
    for (k=0;k<m;k++)
        for (l=1;l<=n;l++){
            if (i[k][i[k][0]]<i[k][l]) i[k][0]=l;
        }
    for (k=0;k<=n;k++)
    z[k]=0;
    for (k=0;k<m;k++)
        z[i[k][0]]++;
    for (k=1;k<=n;k++)
        if (z[num]<z[k]) num=k;
    cout<<num;
    return 0;
}