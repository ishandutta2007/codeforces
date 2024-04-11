#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
long long v[200005];
char c[200005];
int main()
{
    long long i,j,mx=-999999999999LL,pz,n;
    long long mn=-mx;
    cin>>n;
    if(n*1LL*(n+1)%4LL==0)
        cout<<0;
    else
        cout<<1;
}