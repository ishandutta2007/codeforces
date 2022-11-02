#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    set<int> st;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        st.insert(a);
    }
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        if(!st.count(a))
            st.insert(a);
    }
    cout<<n+m-st.size()<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}