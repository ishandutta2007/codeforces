#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void read(int &digit)
{
    digit=0;
    char c;
    for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
    bool type=false;
    if (c=='-')
        type=true,c=getchar();
    for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
    if (type==true)
        digit=-digit;
}

int n,m;
int a[30010];
bool f[30010];
queue<int>  Q;
int main()
{
    read(n),read(m);
    for (int i=1;i<n;i++)   read(a[i]);
    int now=1;
    while (now<m)   now=now+a[now];
    if (now==m) printf("YES\n");else printf("NO\n");
    return 0;
}