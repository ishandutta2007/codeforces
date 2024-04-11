#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
#include<stack>
using namespace std;

struct node{int x;int y;};

int n,m;
long long ans=0,cnt=0;
int sa[100000+5],rrank[100000+5],tax[100000+5],tp[100000+5],height[100000+5];
char s[100000+5];
stack<node>st;

bool cmp(int*f,int x,int y,int w){return f[x]==f[y]&&f[x+w]==f[y+w];}

void ssort(){
    for(int i=0;i<=m;i++)tax[i]=0;
    for(int i=1;i<=n;i++)tax[rrank[tp[i]]]++;
    for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
    for(int i=n;i>=1;i--)sa[tax[rrank[tp[i]]]--]=tp[i];
}

void suffix(){
    for(int i=1;i<=n;i++)rrank[i]=s[i],tp[i]=i;
    m=127;ssort();
    for(int w=1,p=1,i;p<n;w+=w,m=p){
        for(p=0,i=n-w+1;i<=n;i++)tp[++p]=i;
        for(i=1;i<=n;i++)if(sa[i]>w)tp[++p]=sa[i]-w;
        ssort();swap(rrank,tp);rrank[sa[1]]=p=1;
        for(int i=2;i<=n;i++)rrank[sa[i]]=cmp(tp,sa[i],sa[i-1],w)?p:++p;
    }
    for(int i=1,j=0;i<=n;i++){
        if(j)j--;
        while(s[i+j]==s[sa[rrank[i]-1]+j])j++;
        height[rrank[i]]=j;
    }
}

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    ans=(long long)n*(n+1)/2;
    suffix();
    for(int i=1;i<=n;i++){
        node now;now.x=height[i];now.y=1;
        while(!st.empty()&&st.top().x>now.x){
            cnt-=(long long)st.top().x*st.top().y;
            now.y+=st.top().y;
            st.pop();
        }
        cnt+=(long long)now.x*now.y;
        st.push(now);
        ans+=cnt;
    }
    cout<<ans<<endl;
    return 0;
}