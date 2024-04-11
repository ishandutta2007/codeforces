#include<bits/stdc++.h>
using namespace std;
int k,r;
int main()
{
    cin>>k>>r;
    if(k%10==0||k%10==r)
    {
        cout<<1;
        return 0;
    }
    for(int i=2;i<=10;i++)
    if((k*i)%10==0||(k*i)%10==r)
    {
        cout<<i;
		return 0;
    }
}