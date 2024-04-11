#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    string a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    char b,c[n];
    for(int i=0;i<n;i++)
    {
        b=a[i][0];
        for(int j=0;j<m;j++)
        {
            if(b != a[i][j])
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i][0]==a[i+1][0])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}