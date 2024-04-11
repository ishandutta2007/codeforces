#include<bits/stdc++.h>
int n,h,a1,a2,i,endo=1,maxi=0,m,j;
using namespace std;
int flow[500000];
int total_distance[500000];
int wnd[500000];
int steinsgate;
int main()
{
    j=1;
    cin>>n>>h;
    for(i=1;i<=n;i++)
    {
        cin>>a1>>a2;
        //cout<<"Everything is a choice of Steins;Gate\n";
        flow[i]=a1;
        wnd[i]=a2;
        total_distance[i]=total_distance[i-1]+a2-a1;
    }
    for(i=1;i<=n;i++)
    {
        while(h+total_distance[j]-total_distance[i-1]-wnd[j]+flow[i]>0)
        {
            if(j>=n)
            {
                endo=0;
                break;
            }
            j++;
        }
        if(endo!=0)
        {
            j--;
        }
        //cout<<h+total_distance[j]-total_distance[i-1]-wnd[j]+flow[i]<<"\n";
        if(total_distance[j]-total_distance[i-1]+h>maxi)
        {
            maxi=total_distance[j]-total_distance[i-1]+h;
            //cout<<j<<" "<<i<<" "<<total_distance[j]-total_distance[i-1]<<wnd[j]-flow[i]<<"Everything is a choice of Steins Gate El Psy Kongroo\n";
        }
    }
    cout<<maxi;
    return 0;
}