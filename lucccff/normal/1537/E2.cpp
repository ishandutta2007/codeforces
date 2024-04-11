#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

/*int ri() {
    int x = 0, f = 1;
    char ch = getchar();
    for(;ch < '0' || ch > '9'; ch = getchar())
        if(ch == '-')
            f = -1;
    for(;ch >= '0' && ch <= '9'; ch = getchar())
        x = (x << 1) + (x << 3) + ch - '0';
    return x * f;
}*/

char S[N];
int rk[N], tp[N], tax[N], sa[N], n, m , k;

void rsort(){
    for(int i=1;i<=m;i++) tax[i]=0;
    for(int i=1;i<=n;i++) ++tax[rk[i]];//
    for(int i=1;i<=m;i++) tax[i]+=tax[i-1];//
    for(int i=n;i;i--) sa[tax[rk[tp[i]]]--]=tp[i];//
}

void ssort(){
    for(int i=1;i<=n;i++) rk[i]=S[i],tp[i]=i;
    rsort();//1
    for(int w=1,p=0;p<n && w<=n;m=p,w<<=1){
        p=0;//wp
        for(int i=n-w+1;i<=n;i++) tp[++p]=i;//n-w+1~n,
        for(int i=1;i<=n;i++)
            if(sa[i]>w) tp[++p]=sa[i]-w;//
        rsort();
        swap(rk,tp);//
        rk[sa[1]]=p=1;
        for(int i=2;i<=n;i++){
            if(tp[sa[i]]==tp[sa[i-1]] && tp[min(n+1,sa[i]+w)]==tp[min(n+1,sa[i-1]+w)])
                rk[sa[i]]=p;//
            else rk[sa[i]]=++p;
        }
    }
}

int main() {
    cin>>n; cin>>k; m=63;
    scanf("%s",S+1);
    for(int i=1;i<=n;i++) {
        S[i]-=64;
        S[i+n]=S[i];
    }
    n=2*n;
    ssort();
    for(int i = 1;i <= n; ++i)
        rk[sa[i]] = i;
    int j = 0;
    for(j = 2;j <= n; ++j)
        if(rk[j] > rk[1])
            break;
    for(int i = 1;i <= k; ++i)
        putchar(S[(i - 1) % (j - 1) + 1]+64);
    puts("");
    return 0;
}