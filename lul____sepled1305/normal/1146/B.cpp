#include<bits/stdc++.h>
using namespace std;
int f[26];
int h[26];
int i,k,j,l,m;
char cc[1000000];
vector<char> ll;
int main()
{
    scanf("%s",&cc);
    while(cc[i] != '\0')
    {
        f[cc[i]-'a']++;
        if(cc[i]-'a')
        {
            ll.push_back(cc[i]);
        }
        i++;
    }
    for(i=1;i<=25;i++)
    {
        h[i]=f[i]/2;
        if(f[i]%2 != 0)
        {
            k++;
            //cout<<"BUGGGGGGG";
            break;
        }
    }
    //cout<<f['k'-'a']<<h['k'-'a']<<"\n";
    //cout<<ll.size()/2;
    //cout<<"I'm good";
    i=0;
    while(cc[i] != '\0')
    {
        f[cc[i]-'a']--;
        for(j=0;j<=25;j++)
        {
            if(f[j]==h[j])
            {
                l++;
            }
            if(f[j]<h[j])
            {
                k++;
                //cout<<"BUFFF";
            }
        }
        if(l==26)
        {
            m=i;
            break;
        }
        l=0;
        i++;
    }
    for(i=0;i<ll.size()/2;i++)
    {
        if(ll[i]!=ll[i+ll.size()/2])
        {
            k++;
            //cout<<"BUGGGGGGGGG";
        }
    }
    if(k>0)
    {
        cout<<":(";
    }
    else
    {
    for(i=0;i<=m;i++)
    {
        cout<<cc[i];
    }
    }
    //cout<<f['k'-'a']<<h['k'-'a'];
    return 0;
}