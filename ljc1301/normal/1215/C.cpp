#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
char s[maxn],t[maxn];
int n,ans1[maxn],ans2[maxn],tot;
vector<int> pos1,pos2;
int main()
{
    int i,pre=-1;
    scanf("%d%s%s",&n,s,t);
    tot=0; pos1.clear(),pos2.clear();
    for(i=0;i<n;i++)
        if(s[i]=='a' && t[i]=='b')
            pos1.push_back(i);
        else if(s[i]=='b' && t[i]=='a')
            pos2.push_back(i);
    if((pos1.size()+pos2.size())%2==1) { printf("-1\n"); return 0; }
    for(i=pos1.size()%2;i<pos1.size();i+=2)
    {
        ans1[tot]=pos1[i],ans2[tot]=pos1[i+1],tot++;
        swap(s[ans1[tot]],t[ans2[tot]]);
    }
    for(i=pos2.size()%2;i<pos2.size();i+=2)
    {
        ans1[tot]=pos2[i],ans2[tot]=pos2[i+1],tot++;
        swap(s[ans1[tot]],t[ans2[tot]]);
    }
    if(pos1.size()%2==1)
    {
        ans1[tot]=pos1[0],ans2[tot]=pos1[0],tot++;
        ans1[tot]=pos1[0],ans2[tot]=pos2[0],tot++;
    }
    printf("%d\n",tot);
    for(i=0;i<tot;i++)
        printf("%d %d\n",ans1[i]+1,ans2[i]+1);
    return 0;
}