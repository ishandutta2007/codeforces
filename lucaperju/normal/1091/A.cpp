#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
int v[200005];
char ch[200005];
int main()
{
    long long t,n,i,j=0,k=0,s=0,okneg=0,cnt=0,mx=-99999999999999LL,m,cur=0,pz2,pz1,c,a,b,vl1=1,ok=0,sus=1,jos=1;
    cin>>a>>b>>c;
    int ca=a,cb=b,cc=c;
    cc-=2;
    cb--;
    cout<<min(min(ca,cb),cc)*3+3;
}