#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
int v[100003];
int main()
{
    long long t,n,i,j=0,k=0,s=1,okneg=0,cnt=0,mx=-99999999999999LL,m,cur=0,pz,a,b,vl1=1,ok,sus=1,jos=1;
    cin>>n>>i;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
    {
        if(i==1 || v[i]==v[i-1])
            cur=1;
        else
            ++cur;
        if(cur>mx)
            mx=cur;
    }
    cout<<mx;
}
/*
3
8 7
2 3
3 4
4 5
5 2
6 7
7 8
8 6
1 0
2 1
1 2
*/