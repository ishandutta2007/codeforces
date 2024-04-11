#include <iostream>
#include <conio.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    bool a=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            cout << "-1";
            return 0;
        }
    }
    cout<<"1";
    return 0;
}