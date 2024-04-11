#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,t,m,mistake;
long long arr[100];

void split(long long kk)
{
    long long counti=0;
    while(kk)
    {
        arr[counti]+=kk%k;
        kk=kk/k;
        counti++;
    }
}

void clean()
{
    long long ii;
    for(ii=0;ii<100;ii++)
    {
        arr[ii]=0;
    }
}

int main(){
    cin>>t;
    for(i=0;i<t;i++)
    {
        mistake=0;
        cin>>n>>k;
        for(j=0;j<n;j++)
        {
            cin>>m;
            split(m);
        }
        for(j=0;j<100;j++)
        {
            if(arr[j]>1) mistake++;
        }
        clean();
        if(mistake) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}