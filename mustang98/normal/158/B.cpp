#include <iostream>
#include <string>

using namespace std;
int k[4];
int main()
{
    int n, rez=0,a;

    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        k[a-1]++;
    }
    rez+=k[3];
    rez+=k[2];
    k[0]-=k[2];
    if (k[0]<=0) k[0]=0;
    if (k[1]%2==0) rez+=k[1]/2;
    else {rez+=k[1]/2+1; k[0]-=2; if (k[0]<0) k[0]=0;}
    if (k[0]%4==0) rez+=k[0]/4; else rez+=k[0]/4+1;
    cout<<rez;
    return 0;
}