#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000010;
struct Suffix_Automaton
{
    int ch[26],fa,len,right;
}SAM[MAXN];
int root=1,last=1,tot=1;
void Extend(int x)
{
    int np=++tot,p=last;
    SAM[np].len=SAM[p].len+1,SAM[np].right=1;
    while(p&&!SAM[p].ch[x]) SAM[p].ch[x]=np,p=SAM[p].fa;
    if(!p) SAM[np].fa=root;
    else
    {
        int q=SAM[p].ch[x];
        if(SAM[q].len==SAM[p].len+1) SAM[np].fa=q;
        else
        {
            int nq=++tot;
            SAM[nq].len=SAM[p].len+1;
            for(int i=0;i<26;i++) SAM[nq].ch[i]=SAM[q].ch[i];
            SAM[nq].fa=SAM[q].fa;
            SAM[np].fa=SAM[q].fa=nq;
            while(p&&SAM[p].ch[x]==q) SAM[p].ch[x]=nq,p=SAM[p].fa;
        }
    }
    last=np;
}
int c[MAXN],q[MAXN];
void GetRight()
{
    for(int i=1;i<=tot;i++) c[SAM[i].len]++;
    for(int i=1;i<=tot;i++) c[i]+=c[i-1];
    for(int i=1;i<=tot;i++) q[c[SAM[i].len]--]=i;
    for(int i=tot;i>=1;i--) SAM[SAM[q[i]].fa].right+=SAM[q[i]].right;
}
int n;
char p[MAXN];
int Q;
int len,next[MAXN];
char str[MAXN],a[MAXN];
void initKMP()
{
    int j=0;
    for(int i=2;i<=len;i++)
    {
        while(j&&str[j+1]!=str[i]) j=next[j];
        if(str[j+1]==str[i]) j++;
        next[i]=j;
    }
}
int main()
{
    scanf("%s",p);
    n=strlen(p);
    for(int i=0;i<n;i++) Extend(p[i]-'a');
    GetRight();
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%s",str+1);
        len=strlen(str+1);
        initKMP();
        for(int i=0;i<len;i++) a[i]=str[i+1];
        int r=len-next[len];
        if(len%r) r=len;
        for(int i=len;i<len+r-1;i++) a[i]=a[i-len];
        a[len+r-1]=0;
        int x=root,L=0,ans=0;
        for(int i=0;i<len+r-1;i++)
        {
            while(x&&!SAM[x].ch[a[i]-'a']) x=SAM[x].fa,L=SAM[x].len;
            if(!x) x=root;
            if(SAM[x].ch[a[i]-'a']) x=SAM[x].ch[a[i]-'a'],L++;
            while(x&&SAM[SAM[x].fa].len>=len) x=SAM[x].fa,L=SAM[x].len;
            if(L>=len) ans+=SAM[x].right;
        }
        printf("%d\n",ans);
    }
    return 0;
}