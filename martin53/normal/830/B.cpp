#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
pair<int/*value*/,int/*index*/>a[nmax];
bool cmp(pair<int/*value*/,int/*index*/>x,pair<int/*value*/,int/*index*/>y)
{
return x.first<y.first;
}
int pre;
int dist(int a,int b)
{
if(a<=b)return b-a+1;
//a>b
return n-a+b;
}
bool cmp2(pair<int/*value*/,int/*index*/>x,pair<int/*value*/,int/*index*/>y)
{
int dx=dist(pre,x.second),dy=dist(pre,y.second);
return dx<dy;
}
int lsb(int x)
{
return x&(-x);
}
int fenwick[nmax];
void update(int pos)
{
while(pos<=n)
{
fenwick[pos]++;
pos=pos+lsb(pos);
}

}
int pref(int pos)
{
int sum=0;
//cout<<"pos= "<<pos<<endl;
while(pos)
{
sum=sum+fenwick[pos];
pos=pos-lsb(pos);
}
return sum;
}
int sum(int l,int r)
{
if(l>r)return 0;
return pref(r)-pref(l-1);
}
int query(int l,int r)
{
if(l<=r)return (r-l)-sum(l+1,r-1);
return (n-l+1)-sum(l,n)+(r-1+1)-sum(1,r-1);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i].first;
a[i].second=i;
}

sort(a+1,a+n+1,cmp);
pre=0;
for(int i=1;i<=n;i++)
{
    int j=i;
    while(j<=n&&a[i].first==a[j].first)j++;
    j--;
    sort(a+i,a+j+1,cmp2);
    pre=a[j].second;
    i=j;
}

//for(int i=1;i<=n;i++)cout<<a[i].first<<" "<<a[i].second<<endl;

long long ans=0;

for(int i=1;i<=n;i++)
{
ans=ans+query(a[i-1].second,a[i].second);
update(a[i].second);
}
cout<<ans<<endl;

return 0;
}