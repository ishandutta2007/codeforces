
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,l,i[1000001],kol[105],num,ma=-2;
    char t;
    for (k=0;k<1000001;k++)
        i[k]=0;
    for (k=0;k<105;k++)
        kol[k]=0;
    cin>>n;
    for (k=1;k<=n;k++)
    {
        cin>>t>>num;
        if (t=='+') {i[num]++;
            for (l=k;l<=n;l++) kol[l]++;}
        else
            if (i[num]>0) {i[num]--; for (l=k;l<=n;l++) kol[l]--;} else
            {
                for (l=0;l<k;l++)
                kol[l]++;
            }
//        for (l=0;l<=n;l++)
//        cout<<k<<' '<<kol[l]<<endl;
    }
    for (k=0;k<=n;k++)
    {ma=max(ma,kol[k]);
    //cout<<kol[k]<<endl;
    }
    cout<<ma<<endl;
    return 0;
}