#include<bits/stdc++.h>
using namespace std;
const int xmax=1e2+42;
int n,x;
vector< double > inp;
vector< double > merg(vector< double > a,vector< double > b)
{
vector< double > c={};
for(int i=0;i<=x;i++)c.push_back(0);
for(int i=0;i<=x;i++)
    for(int j=0;j<=x;j++)
    c[i^j]+=a[i]*b[j];
//for(auto k:a)cout<<k<<" ";cout<<endl;
return c;
}
vector< double > query(int n_)
{
    if(n_==1)return inp;
    if(n_%2==1)return merg(query(n_-1),inp);
    vector< double > now=query(n_/2);
    //for(auto k:now)cout<<k<<" ";cout<<endl;
    return merg(now,now);
}
int main()
{
scanf("%i%i",&n,&x);
for(int i=0;i<=x;i++)inp.push_back(0);
for(int i=0;i<=x;i++)
    {
    scanf("%lf",&inp[i]);
    }
while((x&(x-1)))
{
    inp.push_back(0);
    x++;
}
printf("%.9f\n",1-query(n)[0]);
return 0;
}