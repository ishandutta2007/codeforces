/*Hina from weathering with you is the second best girl in anime history.*/
#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int gran[n];
        for(i=0;i<n;i++)
            cin>>gran[i];
        sort(gran,gran+n);
        for(i=n-1;i>=0;i--)
        {
            if(gran[i]-i-1<=0)
                break;
        }
        cout<<i+2<<"\n";
    }
    return 0;
}