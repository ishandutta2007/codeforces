#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    int n,i[100],k,kol=0,dkol=-1,ma;
    cin>>n;
    for (k=0;k<n;k++)
    cin>>i[k];
    while (dkol!=0) {
        ma=0;
        for (k=1;k<n;k++)
             if (i[k]>=i[ma]) ma=k;
        if (ma==0) dkol=0; else
        {
            i[ma]--;
            i[0]++;
            kol++;
        }

    }
    cout<<kol;
    return 0;
}