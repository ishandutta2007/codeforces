#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
map<int,int>a;
set<int> cum;
int b[maxn];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<k;i++)
    {
        a[b[i]]++;
        if(a[b[i]]>1)
            cum.erase(b[i]);
        else
            cum.insert(b[i]);
    }
    //shit to codet
    if(!cum.empty())
    cout<<*cum.rbegin()<<endl;
    else
        cout<<"Nothing\n";
    for(int i = k; i < n; i++)
    {
            a[b[i-k]]--;
            if(a[b[i-k]]==1)
                cum.insert(b[i-k]);
            else if(a[b[i-k]]==0)
                cum.erase(b[i-k]);
            a[b[i]]++;
            if(a[b[i]]==1)
                cum.insert(b[i]);
            else if(a[b[i]]>1)
                cum.erase(b[i]);
            if(!cum.empty())
            cout<<*cum.rbegin()<<endl;
            else
                cout<<"Nothing\n";
    }
}