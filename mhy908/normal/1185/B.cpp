#include <bits/stdc++.h>
#define inf 987654321
using namespace std;
typedef long long LL;


int n;
char a[1000010], b[1000010];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%s %s", a, b);
        int pv=0, lena=strlen(a), lenb=strlen(b);
        for(int i=0; i<lenb; i++){
            if(b[i]==a[pv])pv++;
            if(pv==0&&b[i]!=a[pv]){
                printf("NO\n");
                pv=-inf;
                break;
            }
            else if(b[i]!=a[pv]&&b[i]!=a[pv-1]){
                printf("NO\n");
                pv=-inf;
                break;
            }
        }
        if(pv==lena){
            printf("YES\n");
        }
        else if(pv>=0)printf("NO\n");
    }
}