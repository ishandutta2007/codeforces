#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long LL;
int n, m, a, b;
int g, x, y, z;
int arr[9000010];
int mat[3010][3010];
int minmat[3010][3010];
int deq[4000], re, fr;
LL ans;
int main()
{
    scanf("%d %d %d %d %d %d %d %d", &n, &m, &a, &b, &g, &x, &y, &z);
    arr[0]=g;
    for(int i=1; i<=9000000; i++){
        LL temp=(LL)arr[i-1]*x+(LL)y;
        temp%=z;
        arr[i]=(int)temp;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            mat[i][j]=arr[(i-1)*m+j-1];
        }
    }
    for(int i=1; i<=n; i++){
        re=fr=0;
        for(int p=1; p<=m; p++){
            for(int j=re; j>fr; j--){
                if(mat[i][p]<=mat[i][deq[j]])re--;
                else break;
            }
            deq[++re]=p;
            for(int j=fr+1; j<=re; j++){
                if(deq[j]<p-b+1)fr++;
                else break;
            }
            minmat[i][p]=mat[i][deq[fr+1]];
        }
    }
    for(int j=b; j<=m; j++){
        re=fr=0;
        for(int p=1; p<=n; p++){
            for(int i=re; i>fr; i--){
                if(minmat[p][j]<=minmat[deq[i]][j])re--;
                else break;
            }
            deq[++re]=p;
            for(int i=fr+1; i<=re; i++){
                if(deq[i]<p-a+1)fr++;
                else break;
            }
            if(p>=a)ans+=(LL)minmat[deq[fr+1]][j];
        }
    }
    printf("%lld", ans);
}