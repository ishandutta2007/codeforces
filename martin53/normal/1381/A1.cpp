#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

int n;

string a,b;

void query()
{
    cin>>n>>a>>b;

    vector<int> outp={};

    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
        {
            outp.push_back(i);
            outp.push_back(0);
            outp.push_back(i);
        }

    cout<<outp.size()<<endl;
    for(auto k:outp)cout<<k+1<<" ";cout<<endl;
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
        query();
        t--;
    }
    return 0;
}