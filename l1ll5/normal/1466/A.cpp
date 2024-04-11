#include <bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n;
int x[N];
int bin[50*50+5];
int main()
{
    T=read();
    while(T--){
        n=read();
        for(int i=0;i<=50*50+4;i++) bin[i]=0;
        for(int i=1;i<=n;i++) x[i]=read();
        int ans=0;
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) {
            int l=x[j]-x[i];
            if(!bin[l]) ans++;
            bin[l]++;
        }
        cout<<ans<<endl;
    }
}