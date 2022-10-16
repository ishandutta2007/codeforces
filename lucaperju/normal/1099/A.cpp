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
    long long ci,cc,i,j,s=0,cnt0,n,a,b,k=0,ok=0,m,mn=30000003,cnt1,cnt,t,w,h,u1,h1,u2,h2;
  //  long long aib_cat[10006],aib_cst[10006];
    cin>>w>>h>>u1>>h1>>u2>>h2;
    for(i=h;i>=1;--i)
    {
        w+=i;
        if(i==h1)
        {
            w-=u1;
            w=max(w,0LL);
        }
        if(i==h2)
        {
            w-=u2;
            w=max(w,0LL);
        }
    }
    cout<<w;
}