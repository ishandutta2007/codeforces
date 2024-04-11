#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
string a,b;
int k;
cin>>a>>b>>k;


int eq=0;
int not_e=0;


int n=a.size();
for(int i=1;i<=n;i++)
{
    if(a==b)eq++;
    else not_e++;
    a.push_back(a[0]);
    a.erase(0,1);
    //cout<<a<<" "<<b<<endl;
}

//cout<<eq<<" "<<not_e<<endl;

long long good=(a==b),bad=(a!=b);
for(int i=1;i<=k;i++)
{
    long long g_=bad*eq+good*(eq-1);
    long long b_=bad*(not_e-1)+good*not_e;
    g_=g_%mod;
    b_=b_%mod;
    good=g_;
    bad=b_;
}
cout<<good<<endl;
return 0;
}