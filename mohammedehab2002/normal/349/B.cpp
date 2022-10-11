#include <iostream>
using namespace std;
int main()
{
    int n,mini=100000000,i,arr[9],l;
    cin >> n;
    for (i=0;i<9;i++)
    {
        cin >> arr[i];
        if (arr[i]<mini)
        mini=arr[i];
    }
    l=n/mini;
    if (l==0)
    {
        cout << -1;
        return 0;
    }
    while (l--)
    {
        for (i=8;i>=0;i--)
        {
            if ((n-arr[i])/mini==l && n>=arr[i])
            {
                cout << i+1;
                n-=arr[i];
                break;
            }
        }
    }
}