#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

int main()
{
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    if(v[0] == 1)
        cout<<-1;
    else
        cout<<1;
}