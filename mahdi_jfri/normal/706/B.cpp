#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
int a[maxn],j[maxn];
pair<int,int>b[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        cin >> b[i].first;
        b[i].second=i;
    }
    sort(b,b+q);
    int ii=0;
    for(int i=0;i<q;i++)
    {
        while(b[i].first>=a[ii] && ii<n)
            ii++;
        j[b[i].second]=ii;
    }
    for(int i=0;i<q;i++)
        cout<<j[i]<<endl;
}