#include <iostream>
using namespace std;
int main()
{
    int n,d[100],sum=0;
    cin>>n;
    n--;
    for(int i=0;i<n;i++)
        cin>>d[i];
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    for(int i=a;i<b;i++)
        sum+=d[i];
    cout<<sum;
}