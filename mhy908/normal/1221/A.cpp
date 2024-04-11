#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define llinf 8987654321987654321
#define inf 1987654321
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
int q;
int n;
int num[110];
int logg(int p)
{
    if(p==1)return 0;
    return 1+logg(p/2);
}
int main()
{
    scanf("%d", &q);
    for(int u=1; u<=q; u++){
        scanf("%d", &n);
        for(int i=0; i<50; i++)num[i]=0;
        for(int i=1; i<=n; i++){
            int temp;
            scanf("%d", &temp);
            num[logg(temp)]++;
        }
        for(int i=0; i<=10; i++){
            num[i+1]+=num[i]/2;
        }
        if(num[11])printf("YES\n");
        else printf("NO\n");
    }
}