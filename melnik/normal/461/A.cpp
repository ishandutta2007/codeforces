#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,a[300100];
    cin >>n;
    long long sum=0;
    for (int i=0; i<n; i++)
        {cin >>a[i]; sum+=a[i];}
    sort(a,a+n);
    long long ans=sum;
    int kol=n;
    int k=0;
    int nom=0;
    while (kol>1)
    {
        k++;
        ans+=sum;
        sum-=a[nom];
        nom++;
        kol--;
    }
    cout <<ans<<endl;
    return 0;
}