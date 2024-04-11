#include <iostream>

using namespace std;

int main()
{
    int n,x,q=0;
    cin>>n;
    int s[5]={0,0,0,0,0};
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        s[x]++; 
    }
    q=s[4]+s[3];
    s[1]-=s[3];
    q+=s[2]/2;
    q+=s[2]%2;
    s[1]-=2*(s[2]%2);
    if (s[1]>0)
    {q+=(s[1]+3)/4;

    }
    cout<<q;

    return 0;
}