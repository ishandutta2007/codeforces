#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,k,a[nmax];
set<int> numbers;
map<int,int> seen;
void add(int num)
{
//cout<<"adding "<<num<<endl;
if(seen[num]==0)numbers.insert(num);
if(seen[num]==1)numbers.erase(num);
seen[num]++;
}
void unadd(int num)
{
//cout<<"unadding "<<num<<endl;
if(seen[num]==1)numbers.erase(num);
if(seen[num]==2)numbers.insert(num);
seen[num]--;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];

for(int i=1;i<k;i++)
    add(a[i]);
for(int i=k;i<=n;i++)
{
add(a[i]);
if(numbers.size()==0)cout<<"Nothing"<<endl;
else
{
set<int>::iterator q=numbers.end();
q--;
cout<</*"query= "<<*/*q<<endl;
}
//cout<<"numbers: ";for(auto k:numbers)cout<<k<<" ";cout<<endl;
unadd(a[i-k+1]);
}
return 0;
}