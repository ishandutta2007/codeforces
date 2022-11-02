#include<bits/stdc++.h>
using namespace std;
int i=1,j,k,n,l,p;
int main()
{
    cout<<"2000\n";
    cin>>n;
    p=n/1999+1;
    while(((p*1999)-n)%2000)
    {
        p++;
    }
    j=((p*1999)-n)/2000;
    for(i=0;i<2000;i++)
    {
        if(i<1998)
        {
            printf("0 ");
        }
        else if(i==1998)
        {
            printf("%d ",-j);
        }
        else
        {
            printf("%d",p);
        }
    }
    return 0;
}