#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=100;
bool isp[maxn];
int aval[maxn];
int z=0;
int main()
{
    for(int i=2;i < maxn;i++)
    {
        if(isp[i]==0)
        {
            aval[z++]=i;
            for(long long j=i; j<maxn; j+=i)
            {
                isp[j]=1;
            }
        }
    }
    int t=0;
    int i=0;
    int x=1;
    while(x*aval[i]<=100 && (aval[i]<10 || t==1))
    {
        cout<<aval[i]<<endl;
        string s;
        cin>>s;
        if(s=="yes")
        {
            x*=aval[i];
            t++;
        }
        i++;
        if(t>1)
        {
            cout<<"composite"<<endl;
            return 0;
        }
    }
    if(x<10 && x>1)
    {
        cout<<x*x<<endl;
        string s;
        cin>>s;
        if(s=="no")
            cout<<"prime"<<endl;
        else
            cout<<"composite"<<endl;
    }
    else cout<<"prime"<<endl;
}