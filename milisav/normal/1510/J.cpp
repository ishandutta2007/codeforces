#include <bits/stdc++.h>
using namespace std;
int n,mn;
string s;
vector<int> b,p,c,sol;
void zavrsi()
{
    printf("%d\n",sol.size());
    for(int i=0;i<sol.size();i++) printf("%d ",sol[i]);
    exit(0);
}
void pokusaj(int x)
{
    if(x==0)
    {
        for(int i=0;i<b.size();i++) if(b[i]!=0) return;
        sol=c;
        zavrsi();
    }
    if(x==1)
    {
        for(int i=0;i<b.size();i++) if((b[i]-x)%2!=0) return;
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<(b[i]-x)/2;j++) sol.push_back(1);
            if(i+1!=b.size()) sol.push_back(c[i]+1);
        }
        zavrsi();
    }
    for(int i=0;i<b.size();i++) if((b[i]-x)<0 || (b[i]-x)==1) return;
    for(int i=0;i<b.size();i++)
    {
        int t=(b[i]-x);
        if(t%2==1) {sol.push_back(2); t-=3;}
        for(int j=0;j<t/2;j++) sol.push_back(1);
        if(i+1!=b.size()) sol.push_back(c[i]+x);
    }
    zavrsi();
}
int main()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++) if(s[i]=='#') p.push_back(i);
    if(p.size()==0) {printf("0"); return 0;}
    b.push_back(p[0]);
    for(int i=1;i<p.size();i++) if(p[i]>p[i-1]+1) b.push_back(p[i]-p[i-1]-2);
    b.push_back(n-1-p[p.size()-1]);
    int rt=0; mn=b[0];
    for(int i=0;i<b.size();i++) mn=min(mn,b[i]);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='_') rt=0;
        else
        {
            rt++;
            if(i+1==s.size() || s[i]!=s[i+1]) {c.push_back(rt); rt=0;}
        }
    }
    pokusaj(0); pokusaj(1); pokusaj(2); pokusaj(mn);
    printf("-1");
}