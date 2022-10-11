#include <iostream>
using namespace std;
int solve(int x)
{
    int i;
    for (i=0;i<=x;i+=4)
    {
        if ((x-i)%7==0)
        return i/4;
    }
    return -1;
}
int main()
{
    int n,i;
    cin >> n;
    int ans=solve(n);
    if (ans==-1)
    {
        cout << -1;
        return 0;
    }
    for (i=0;i<ans;i++)
    cout << 4;
    n-=ans*4;
    for (i=0;i<n/7;i++)
    cout << 7;
}