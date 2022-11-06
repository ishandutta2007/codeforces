#include <iostream>

using namespace std;

int main()
{
    int n,x1,x2,y1,y2,kol=0;
    cin>>n;
    for (;n>0;n--)
    {
        cin>>x1>>y1>>x2>>y2;
        kol+=(x2-x1+1)*(y2-y1+1);
    }
    cout<<kol;
    return 0;
}