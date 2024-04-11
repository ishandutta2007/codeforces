#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define rvc(i,S) for(int i=0;i<S.size();++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define N 100005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
string s[N];
string t[N];
int n,m;
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)cin>>s[i-1];
    for(int i=1;i<=m;i++)cin>>t[i-1];
    int q=read();
    while(q--)
    {
        int x=read()-1;
        int a1=x%n;
        int b1=x%m;
        cout<<s[a1]+t[b1]<<endl;

    }
}