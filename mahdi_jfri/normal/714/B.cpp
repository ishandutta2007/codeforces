#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
vector<int>v;
ll a[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    v.push_back(a[0]);
    for(int i=0;i<n;i++)
    {
        if(a[i] != v.back())
            v.push_back(a[i]);
    }
    int c=v.size();
    if(c>3)
    {
        cout<<"NO";
        exit(0);
    }
    else
    {
        if(c<3)
        {
            cout<<"YES";
            exit(0);
        }
        else
            if(v[0]-v[1]==v[1]-v[2])
                cout<<"YES";
            else
                cout<<"NO";
    }
}