#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int x[4],y[4],n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    sort(x,x+n);
    sort(y,y+n);
    if (n==1) cout<<-1<<endl;
    if (n==2)
        if (x[0]==x[1] || y[0]==y[1]) cout<<-1<<endl;
        else cout<<abs(x[1]-x[0])*abs(y[1]-y[0])<<endl;
    if (n==3 || n==4) cout<<abs( (x[n-1]-x[0])*(y[n-1]-y[0]) )<<endl;
    return 0;
}