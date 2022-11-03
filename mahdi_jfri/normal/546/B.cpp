#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,a[3010],x=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
            {
                int i1=i;
                while(a[i1]==a[i1+1] && i1<n-1)
                    i1++;
                for(int j=i1;j>=i;j--)
                {
                    a[j]+=(-i+j);
                    x+=j-i;
                }
                i=-1;
                sort(a,a+n);
            }
    }
    cout<<x;
}