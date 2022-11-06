#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,i[100000];
    cin>>n;
    for (k=0;k<n;k++)
    cin>>i[k];
    cout<<i[1]-i[0]<<' '<<i[n-1]-i[0]<<endl;
    n--;
    for (k=1;k<n;k++)
    {
        int x1,x2,y1,y2;
        x1=i[k]-i[k-1];
        x2=i[k+1]-i[k];
        y1=i[n]-i[k];
        y2=i[k]-i[0];
        cout<<min(x1,x2)<<' '<<max(y1,y2)<<endl;
    }
    cout<<i[n]-i[n-1]<<' '<<i[n]-i[0]<<endl;
    return 0;
}