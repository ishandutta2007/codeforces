#include<bits/stdc++.h>
using namespace std;
const int nmax=15e4+42;
long long A[nmax],B[nmax];
set<int> d;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
int n;
long long a,b;
long long ans=0;
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a>>b;
    long long p=a*b/__gcd(a,b);
    ans=__gcd(ans,p);
    A[i]=a;
    B[i]=b;
}
if(ans==1)cout<<-1<<endl;
else
{
    for(int i=1;i*i<=A[1];i++)
        if(A[1]%i==0){d.insert(i);d.insert(A[1]/i);}
    swap(A[1],B[1]);

    for(int i=1;i*i<=A[1];i++)
        if(A[1]%i==0){d.insert(i);d.insert(A[1]/i);}
    for(auto k:d)
        if(k!=1)
        if(ans%k==0)
        {
        cout<<k<<endl;
        return 0;
        }
    assert(0==1);
}
return 0;
}