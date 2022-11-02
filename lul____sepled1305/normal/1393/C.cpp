#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i;
        cin>>n;
        int cake[n];
        int type[n];
        for(i=0;i<n;i++)
        {
            cin>>cake[i];
            cake[i]--;
            type[i] = 0;
        }
        for(i=0;i<n;i++)
            type[cake[i]]++;
        sort(type,type+n,greater<int>());
        int mini = n;
        int counti = 0;
        for(i=0;i<n;i++)
        {
            if(type[i]==type[0])
                counti++;
        }
        if(type[0] == 1)
            cout<<0<<"\n";
        else
            cout<<(n-counti)/(type[0]-1) - 1<<"\n";
    }
}