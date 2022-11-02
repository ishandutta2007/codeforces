#include<bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const int N = 2e5+10;
long long n,m,i,j,ans =1;
long long a[N], b[N];
long long last[N];
long long meme[N];

int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<m;i++)
        cin>>b[i];
    bool pass = true;
    int pointer = m-1;
    map<long long,int> mp;
    for(i=0;i<m;i++)
        mp.insert({b[i],i});
    bool con = true;
    for(i=n-1;i>=0;i--)
    {
        while(con && a[i]<b[pointer])
        {
            last[pointer] = i;
            pointer--;
            if(pointer==-1)
            {
                con = false;
                break;
            }
        }
        if(a[i]<b[0])
        {
            pass = false;
        }
        if(mp.count(a[i]) && meme[mp[a[i]]] == 0)
            meme[mp[a[i]]] = i;
    }
    for(i=0;i<m-1;i++)
    {
        if(meme[i]==0 && a[0]!=b[i])
            pass =false;
    }
    for(i=0;i<m-1;i++)
    {
        if(meme[i+1]-last[i+1]>0)
            ans*=(meme[i+1]-last[i+1]);
        else
            pass = false;
        ans%=MOD;
    }
    if(m==1)
    {
        if(meme[0]==0 && a[0]!=b[0])
            ans = 0;
        else
        {
            ans = 1;
        }
    }
    if(pass)
        cout<<ans;
    else
        cout<<0;
}