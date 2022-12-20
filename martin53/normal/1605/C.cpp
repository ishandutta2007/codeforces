#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;

int n;
string inp;

int solve()
{
    cin>>n;
    cin>>inp;

    int outp=INF;

    for(int i=0;i<n;i++)
    {
        int cnt[3]={0,0,0};

        for(int j=i;j<n&&j-i+1<=7;j++)
        {
            cnt[inp[j]-'a']++;

            if(i<j&&cnt[0]>cnt[1]&&cnt[0]>cnt[2])outp=min(outp,j-i+1);
        }
    }

    if(outp==INF)return -1;
    return outp;
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

        cout<<solve()<<"\n";
    }

    return 0;
}