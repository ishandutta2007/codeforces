# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cstring>

using namespace std;
const int maxn=200010;

struct T{ int x,y; }a[maxn];
bool operator<(const T&a, const T&b)
{
    return a.x<b.x;
}

long long ans=1;
int n,m,c[maxn],Mod;

void solve()
{
    int del=0,k;
    long long tmp=1;
    sort(c,c+m);
    for(int i=0;i<m-1;i++)
        if(c[i]==c[i+1])del++;
    for(int i=2;i<=m;i++)
    {
        k=i;
        while((~k&1)&&(del>0))k=k>>1,del--;
        tmp=tmp*k%Mod;
    }
    ans=ans*tmp%Mod;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].x);
        a[i].y=i;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i+n].x);
        a[i+n].y=i;
    }
    sort(a,a+n+n);
    cin >> Mod;
    
    int i,j;
    for(i=0;i<n*2;i=j+1)
    {
        for(j=i+1;j<n*2;j++)
            if(a[i].x!=a[j].x)break;
        j--;
        if(i==j)continue;
        memset(c,0,sizeof(c));
        for(int k=i;k<=j;k++)
            c[k-i]=a[k].y;
        m=j-i+1;solve();
    }
    cout << ans << endl;
}