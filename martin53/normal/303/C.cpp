#include<bits/stdc++.h>
using namespace std;
const int nmax=5e3+42,lim=1e6+42;
int n,a[nmax],k;
int pairs[lim];
int c[nmax];
void test(int m)
{
    //cout<<"testing "<<m<<endl;
    for(int i=1;i<=n;i++)c[i]=a[i]%m;
    sort(c+1,c+n+1);
    int now=0;
    for(int i=2;i<=n;i++)
        if(c[i-1]==c[i])now++;
    if(now<=k)
    {
        cout<<m<<endl;
        exit(0);
    }
}
int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];

for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
        pairs[abs(a[i]-a[j])]++;

for(int i=1;i<lim;i++)
    for(int d=2*i;d<lim;d=d+i)
    pairs[i]=pairs[i]+pairs[d];

for(int m=1;true;m++)
    if(pairs[m]<=k*(k+1)/2)
    {
        test(m);
    }
return 0;
}