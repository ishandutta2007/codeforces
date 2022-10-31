#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{string a;int b;} a[360002];
string s[10002],c[40],ss;
int n,m,i,l,r,j,cnt,k,z;
bool cmp(node a,node b)
{
    return a.a<b.a;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
        k=0;
        z=s[i].length();
        for(l=0;l<z;l++)
           for(r=l;r<z;r++)
           {
               k++;
               c[k]="";
               for(j=l;j<=r;j++) c[k]=c[k]+s[i][j];
           }
        sort(c+1,c+k+1);
        for(j=1;j<=k;j++)
        {
            if(c[j]==c[j-1]) continue;
            cnt++;
            a[cnt].a=c[j];
            a[cnt].b=i;
        }
    }
    sort(a+1,a+cnt+1,cmp);
    cin>>m;
    while(m--)
    {
        cin>>ss;
        l=1;
        r=cnt;
        while(l<r)
        {
            k=(l+r)>>1;
            if(a[k].a>=ss) r=k;
            else l=k+1;
        }
        if(a[r].a==ss)
        {
            z=r;
            l=1;
            r=cnt;
            while(l<r)
            {
                k=(l+r)>>1;
                if(a[k].a>ss) r=k;
                else l=k+1;
            }
            if(a[r].a==ss) r++;
            cout<<r-z<<" "<<s[a[z].b]<<"\n";
        }
        else cout<<"0 -\n";
    }
    return 0;
}