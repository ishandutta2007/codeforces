#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
struct Trie
{
    int ch[2],cnt;
}T[MAXN*32];
int root=1,tot=1;
int n;
void insert(int o)
{
    int x=root;
    T[x].cnt++;
    for(int i=30;i>=0;i--)
    {
        int c=0;
        if(o&(1<<i)) c=1;
        else c=0;
        if(!T[x].ch[c]) T[x].ch[c]=++tot;
        x=T[x].ch[c];
        T[x].cnt++;
    }
}
void remove(int o)
{
    int x=root;
    T[x].cnt--;
    for(int i=30;i>=0;i--)
    {
        int c=0;
        if(o&(1<<i)) c=1;
        else c=0;
        x=T[x].ch[c];
        T[x].cnt--;
    }
}
int query(int o)
{
    int x=root,ans=0;
    for(int i=30;i>=0;i--)
    {
        int c=0;
        if(o&(1<<i)) c=1;
        else c=0;
        if(T[T[x].ch[c^1]].cnt) x=T[x].ch[c^1],ans^=(1<<i);
        else x=T[x].ch[c];
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    insert(0);
    while(n--)
    {
        char s[10];
        int x;
        scanf("%s%d",s,&x);
        if(s[0]=='+') insert(x);
        else if(s[0]=='-') remove(x);
        else printf("%d\n",query(x));
    }
    return 0;
}