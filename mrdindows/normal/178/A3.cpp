#include <iostream>
#include <math.h>
typedef long long lli; 
using namespace std;

int main()
{
    int n;
    cin>>n;
    int *a=new int[100001];
    for (int i=1;i<n+1;i++)
    {
        cin>>a[i];
    }
    lli c=0;
    for (int k=1;k<n;k++)
    {
        if (a[k]>0)
        {
            c+=a[k];;
            a[k+(int)pow(2.0,(int)(log((double)(n-k))/log(2.0)))]+=a[k];
            a[k]=0;
        }
        cout<<c<<endl;
    }

    return 0;
}