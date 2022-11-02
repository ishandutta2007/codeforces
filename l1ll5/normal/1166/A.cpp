#include <bits/stdc++.h>
#define N 100000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char s[N];
map<char,int> mp;
int main()
{
    int n=read();

    while(n--)
    {
        cin>>s;
        mp[s[0]]++;
    }
    ll ans=0;
    for (auto it : mp)
    {
        int a=it.second/2,b=it.second-a;
        ans+=a*(a-1)/2;
        ans+=b*(b-1)/2;
    }
    cout<<ans<<endl;
}