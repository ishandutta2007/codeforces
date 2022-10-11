#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n,arr[7],i;
    cin >> n;
    for (i=0;i<7;i++)
    cin >> arr[i];
    i=-1;
    while (n>0)
    {
        i++;
        if (i==7)
        i=0;
        n-=arr[i];
    }
    cout << i+1;
}