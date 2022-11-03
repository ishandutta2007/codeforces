#include<iostream>
using namespace std;
//int a[110];
int main()
{
    int n;
    cin>>n;
    int x=0;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b+c>1)
            x++;
    }
    cout<<x;
}