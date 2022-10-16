#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    long long ci,cc,i,j,s=0,cnt=0,cnt0=0,n,a;
    cin>>n;
    a=sqrt(n);
    if(a*a==n)
        cout<<a*2LL;
    else if (a*1LL*(a+1)>=n)
        cout<<a*2LL+1;
    else
        cout<<a*2LL+2;
}