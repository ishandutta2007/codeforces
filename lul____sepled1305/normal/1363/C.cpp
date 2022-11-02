/*(Spoiler Alert) Tiat is the next Seniorious user.*/
#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,x,i,counti=0;
        bool first = false;
        cin>>n>>x;
        for(i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            if(a==x || b==x)
                counti++;
        }
        if(counti==1 || counti==0)
            first = true;
        else if(n%2==1)
            first = false;
        else
            first = true;
        if(first)
            cout<<"Ayush\n";
        else
            cout<<"Ashish\n";
    }
    return 0;
}