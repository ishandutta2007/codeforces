#include<iostream>
using namespace std;
int Test(int a)
{
    if(a<0)a=-a;
    while(a>0)
    {
        if(a%10==8)
            {
                return 1;
            }
        else
        {
            a/=10;
        }
    }
    return 0;
}
int main()
{
    int a,b=0,i=1;
    cin>>a;
    while(b==0)
    {
        a++;
        b=Test(a);
        i++;
    }
    cout<<i-1;
}