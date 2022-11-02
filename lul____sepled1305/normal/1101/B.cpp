#include<bits/stdc++.h>
using namespace std;
char a[500010];
int n,m,k,l,i,o,fir=1e9,las,co,j,lol;
int main()
{
    scanf("%s",&a);
    while(a[i]!='\0')
    {
        if(a[i]=='[')
        {
            break;
        }
        i++;
    }
    //cout<<i;
    if(a[i]=='\0')
    {
        lol=1e9;
    }
    while(a[j]!='\0')
    {
        if(a[j]==']')
        {
            l=j;
        }
        j++;
    }
    //cout<<l;
    //cout<<"BUG";
    for(o=i;o<=l;o++)
    {
        if(a[o]==':')
        {
            if(fir>o)
            {
                fir=o;
            }
            if(las<o)
            {
                las=o;
            }
        }
    }
    if(fir==las || lol==1e9 || l==0 ||i>l ||fir==1e9||las==0)
    {
        cout<<-1;
    }
    else
    {
        for(o=fir;o<=las;o++)
        {
            if(a[o]=='|')
            {
                co++;
            }
        }
        cout<<co+4;
    }
    return 0;
}