#include <bits/stdc++.h>
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
int T;
int n;
char s[N];
int x[N];
int bin[50];
int find(int p) {
    for(int i=max(1,p-2);i<=min(n,p+2);i++)
    if(i!=p)
    {
        bin[x[i]]++;
    }

    if(!bin[x[p]]) {
        for(int i=0;i<26;i++)bin[i]=0;
        return x[p];
    }

    int ok=0;
    for(int i=0;i<26;i++)
    if(!bin[i]) ok=i;
    for(int i=0;i<26;i++)bin[i]=0;
    return ok;
}
int main()
{
    T=read();
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=1;i<=n;i++) x[i]=s[i]-'a';

        int ans=0;
        for(int i=2;i<=n;i++) {
            if( i == 2 ) {
                if(x[i]==x[i-1]){
                    int o=find(i);
                    ans += (o!=x[i]);
                    x[i] = o;
                }
            }
            else {
                if(x[i] == x[i-1] || x[i] == x[i-2])
                {
                    int o=find(i);
                    ans += (o!=x[i]);
                    x[i] = o;
                }
            }
        }

        printf("%d\n",ans);

    }
}