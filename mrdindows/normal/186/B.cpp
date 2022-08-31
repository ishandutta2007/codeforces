#include <iostream>
#include <math.h>
#include <algorithm>
typedef long long lli; 
using namespace std;

int main()
{
    long n,t1,t2,k;
    cin>>n>>t1>>t2>>k;
    double *a=new double[n];
    double *b=new double[n];
    for (int i=0;i<n;i++)
    {
        long v1,v2;
        cin>>v1>>v2;
        a[i]=max(v1*t1*(100-k)/100.0+t2*v2,v2*t1*(100-k)/100.0+t2*v1);
        b[i]=i;
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<n-1;j++)
        {
            if (a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
                swap(b[j],b[j+1]);
            }
        }
    for (int i=0;i<n;i++)
    {
        cout.precision(0);
        cout<<1+b[i]<<" ";
            cout<<fixed;
            cout.precision(2);
            cout<<a[i]<<endl;
    }
    return 0;
}