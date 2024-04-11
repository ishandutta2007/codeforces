#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int MAXN=2000010;
typedef long long LL;
LL len,k,next[1000010];
int head[MAXN],to[MAXN],next_2[MAXN],cnt=1;
char str[1000010];
bool ans[1000010];
multiset<LL> S;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next_2[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next_2[cnt]=head[t],head[t]=cnt;
}
void initKMP()
{
    int j=0;
    for(int i=2;i<=len;i++)
    {
        while(j!=0&&str[i]!=str[j+1]) j=next[j];
        if(str[j+1]==str[i]) j++;
        next[i]=j;
    }
}
void DFS(int x,int fa)
{
    S.insert(-k*(k+1)*(LL)x);
    LL l=k*(LL)x-k*(k+1)*(LL)x,r=(k+1)*(LL)x-k*(k+1)*(LL)x;
    LL P=(*S.lower_bound(l));
    if(P>=l&&P<=r) ans[x]=true;
    for(int i=head[x];i;i=next_2[i])
        if(to[i]!=fa)
            DFS(to[i],x);
    multiset<LL>::iterator it=S.find(-k*(k+1)*(LL)x);
    S.erase(it);
}
int main()
{
    scanf("%I64d%I64d%s",&len,&k,str+1);
    initKMP();
    for(int i=1;i<=len;i++)
        if(next[i]!=0) adde(i,next[i]);
    S.insert(0);
    for(int i=1;i<=len;i++)
        if(next[i]==0) DFS(i,-1);
    for(int i=1;i<=len;i++)
        if(ans[i]) putchar('1');
        else putchar('0');
    puts("");
    return 0;
}