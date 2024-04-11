#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const LL llinf=9000000000000000000;
const int inf=2000000000;
int n;
LL num;
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld", &num);
        if(num<=14)puts("NO");
        else if(num%14<=6&&num%14)puts("YES");
        else puts("NO");
    }
}