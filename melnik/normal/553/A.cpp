#include <iostream>

using namespace std;
int main()
{
    int k,i[1000],l,j[1000],p,dl;
    long long h=1;
    for (l=0;l<1000;l++)
    j[l]=0;
    cin>>k;
    for (l=0;l<k;l++)
    cin>>i[l];
    dl=i[0];
    for (l=1;l<k;l++)
    {
        for (int y=1;y<i[l];y++)
        {
            p=dl+1;
            for (int u=2;u<=p;u++)
            {
                while (p%u==0)
                {
                    j[u]++;
                    p/=u;
                }
            }
            dl++;
        }
        for (int q=2;q<i[l];q++)
        {
            int y=q;
            for (int u=2;u<=y;u++)
            while (y%u==0)
            {
                j[u]--;
                y/=u;
            }
        }
        dl++;
    }
    for (l=0;l<1000;l++)
    while (j[l]>0)
    {
        j[l]--;
        h*=l;
        h%=1000000007;
    }
    cout<<h;
    return 0;
}