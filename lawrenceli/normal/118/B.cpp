#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=0; i<2*n; i++) cout << " ";
    cout << 0 << endl;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<2*(n-i); j++) cout << " ";
        for (int j=0; j<i; j++)
        {
            cout << j << " ";
        }
        cout << i << " ";
        for (int j=i-1; j>0; j--)
        {
            cout << j << " ";
        }
        cout << 0;
        cout << endl;
    }
    for (int i=n-1; i>0; i--)
    {
        for (int j=0; j<2*(n-i); j++) cout << " ";
        for (int j=0; j<i; j++)
        {
            cout << j << " ";
        }
        cout << i << " ";
        for (int j=i-1; j>0; j--)
        {
            cout << j << " ";
        }
        cout << 0;
        cout << endl;
    }
    for (int i=0; i<2*n; i++) cout << " ";
    cout << 0 << endl;
}