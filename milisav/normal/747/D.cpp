#include<bits/stdc++.h>
using namespace std;
int n,k;
int l=0;
int s=0;
priority_queue<int> a;
int b[300000];
bool p;
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        if((b[i-1]>=0 && b[i]<0) || (b[i-1]<0 && b[i]>=0)) s++;
        if(b[i]<0)
        {
            k--;
            if(l>0 && p) a.push(-l);
            p=true;
            l=0;
        }
        else l++;
    }
    if(!p)
    {
        printf("0");
        return 0;
    }
    if(k<0)
    {
        printf("-1");
        return 0;
    }
    while(k>=0 && a.size()>0)
    {
        k+=a.top();
        if(k<0)
        {
        	k-=a.top();
        	break;
        }
        a.pop();
        s-=2;
    }
    if(k>=l && l>0) s--;
    printf("%d",s);
    return 0;
}