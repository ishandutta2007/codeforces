#include<bits/stdc++.h>
using namespace std;
long long x,y,i,j,r;
int main()
{
    cin>>r;
    r--;
    for(i=1;i<=sqrt(r-1);i++)
    {
        if(r%i==0)
        {
            if(((r/i)-1-i)%2==0 && ((r/i)-1-i)>0)
            {
                j++;
                break;
            }
        }
    }
    if(j==0)
    {
        cout<<"NO";
    }
    else
    {
        cout<<i<<" "<<(r-1-i)/2;
    }
    return 0;
}