/**
 * @file CF888E.cpp
 * @author Macesuted
 * @date 2020-12-22
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define bufferSiz 1 << 16
char buff[bufferSiz], *_S = buff, *_T = buff;
#define getchar() (_S == _T && (_T = (_S = buff) + fread(buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -f;

        c = getchar();
    }
    while (isdigit(c)) {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

#define maxn 36

int a[maxn];
vector<int> p[2];
int n,m;

void dfs(int b,int e,int t,int sum)
{
    if(b>e) return p[t].push_back(sum);
    return dfs(b+1,e,t,(sum+a[b])%m),dfs(b+1,e,t,sum);
}

int main() {
    n=read<int>(),m=read<int>();
    for(register int i=1;i<=n;i++) a[i]=read<int>();
    if(n==1) { printf("%d\n",a[1]%m); return 0; }
    dfs(1,n/2,0,0),dfs(n/2+1,n,1,0);
    sort(p[0].begin(),p[0].end()),sort(p[1].begin(),p[1].end());
    int ans=(*p[0].rbegin()+*p[1].rbegin())%m;
    for(vector<int>::iterator i=p[0].begin(),j=p[1].end()-1;i!=p[0].end();i++)
    {
        while(*i+*j>=m) j--;
        ans=max(ans,*i+*j);
    }
    printf("%d\n",ans);
    return 0;
}