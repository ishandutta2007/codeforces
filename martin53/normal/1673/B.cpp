#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    string inp;
    cin>>inp;

    set<int> st={};
    for(auto w:inp)
        st.insert(w);

    int SZ=st.size();

    for(int i=inp.size()-1;i>=SZ;i--)
        if(inp[i]!=inp[i-SZ])return 0;

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        if(solve())cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}