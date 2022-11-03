#include<iostream>
using namespace std;
int main()
{
    int a,e[52],o[52],x=1,y=1,b=1;
    cin>>a;
    if(a%2!=0)
        cout<<"-1";
    else
    {
        for(int i=0;i<=a;i+=2)
        e[i/2]=i;
    for(int i=1;i<a;i+=2)
        {
            o[b]=i;
            b++;
        }
    for(int i=1;i<=a;i++)
    {
        if(i%2==1)
            {
                cout<<e[x]<<" ";
                x++;
            }
        else
            {
                cout<<o[y]<<" ";
                y++;
            }
    }
    }
}