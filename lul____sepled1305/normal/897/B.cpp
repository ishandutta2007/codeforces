#include<bits/stdc++.h>
using namespace std;
long long int a,b,c,i,j,n,k,l,p,sum,palin;
int main()
{
    cin>>n>>p;
    for(i=1;i<=n;i++)
    {
        if(i<10)
        {
            palin=i+10*i;
            //cout<<palin<<" ";
        }
        else if(i<100)
        {
            palin=1001*(i/10);
            palin+=110*(i%10);
        }
        else if(i<1000)
        {
            palin=100001*(i/100);
            palin+=10010*(i/10-(10*(i/100)));
            palin+=1100*(i-(10)*(i/10));
        }
        else if(i<10000)
        {
            palin=10000001*(i/1000);
            palin+=1000010*(i/100-(10*(i/1000)));
            palin+=100100*(i/10-(10*(i/100)));
            palin+=11000*(i-10*(i/10));
        }
        else if(i<100000)
        {
            palin=1000000001*(i/10000);
            palin+=100000010*(i/1000-(10*(i/10000)));
            palin+=10000100*(i/100-(10*(i/1000)));
            palin+=1001000*(i/10-(10*(i/100)));
            palin+=110000*(i-10*(i/10));
        }
        else 
        {
            palin=100000000001;
        }
        sum+=palin;
        sum%=p;
    }
    cout<<sum;
    return 0;
}