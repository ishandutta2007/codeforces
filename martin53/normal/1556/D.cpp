#include<bits/stdc++.h>
using namespace std;

long long sum_of(int i,int j)
{
    cout<<"or "<<i<<" "<<j<<endl;

    long long p;

    cin>>p;

    cout<<"and "<<i<<" "<<j<<endl;

    long long q;

    cin>>q;

    return p+q;
}

const int nmax=1e6+42;

int inp[nmax];

int main()
{
    int n,k;
    cin>>n>>k;

    long long s12=sum_of(1,2);

    long long s23=sum_of(2,3);

    long long s31=sum_of(3,1);

    inp[1]=(s12+s31-s23)/2;
    inp[2]=(s12+s23-s31)/2;
    inp[3]=(s23+s31-s12)/2;

    for(int i=4;i<=n;i++)
        inp[i]=sum_of(1,i)-inp[1];

    sort(inp+1,inp+n+1);

    cout<<"finish "<<inp[k]<<endl;

    return 0;
}