#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        unordered_set<int>se;
        for(int x=1;x*x*x<=n;x++)
        se.insert(x*x*x);
        for(int x=1;x*x<=n;x++)
        se.insert(x*x);
        cout<<se.size()<<endl;
    }
}