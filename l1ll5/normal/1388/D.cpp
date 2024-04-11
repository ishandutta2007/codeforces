#include <bits/stdc++.h>
#define N 400005
#define int long long
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
int a[N];
int b[N];

int deg[N];
int ans;

queue<int> q;

vector<int> v1,v2;

main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();

    for(int i=1;i<=n;i++){
        if(b[i]!=-1)
        deg[b[i]]++;
    }

    for(int i=1;i<=n;i++)
    if(deg[i]==0){
        q.push(i);
    }

    while(!q.empty()){
        int x=q.front(); q.pop();

        ans+=a[x];

        if(b[x]==-1){
            v1.push_back(x);
            continue ;
        }

        if(a[x]>0){
            a[b[x]]+=a[x];
            v1.push_back(x);
        }else{
            v2.push_back(x);
        }

        deg[b[x]]--;
        if(deg[b[x]]==0) q.push(b[x]);
    }
    reverse(v2.begin(),v2.end());

    printf("%lld\n",ans);
    for(int i=0;i<v1.size();i++) printf("%lld ",v1[i]);
    for(int i=0;i<v2.size();i++) printf("%lld ",v2[i]);

}