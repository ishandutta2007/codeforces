
 #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,SIZE=450;
int n;
int values[nmax];
pair<int/*where*/,int/*steps*/> jump[nmax];

void evaluate(int bucket)
{
    int high=min(n-1,SIZE*bucket+SIZE-1),stop=bucket*SIZE;
    for(int j=high;j>=stop;j--)
    {
        if(j+values[j]>high)jump[j]={j,0};
        else jump[j]={jump[j+values[j]].first,1+jump[j+values[j]].second};
    }
}
void query(int where)
{
    int ans=0;
    while(where<n)
    {
        ans=ans+jump[where].second;
        where=jump[where].first;
        ans++;
        if(where+values[where]>=n)
        {
        cout<<where+1<<" "<<ans<<endl;
        return;
        }
        where=where+values[where];
    }

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
int m,type,a,b;
cin>>n>>m;
for(int i=0;i<n;i++)cin>>values[i];
for(int i=0;i*SIZE<n;i++)evaluate(i);

for(int i=1;i<=m;i++)
{
    cin>>type;
    if(type==0)
    {
        cin>>a>>b;
        a--;
        values[a]=b;
        evaluate(a/SIZE);
    }
    else
    {
        cin>>a;
        a--;
        query(a);
    }
}
return 0;
}