#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define llinf 8987654321987654321
#define inf 1987654321
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

int a1, a2, k1, k2, n;
int maxx, minn;
int num1, num2;

int main()
{
    scanf("%d %d %d %d %d", &a1, &a2, &k1, &k2, &n);
    if(k1>k2)swap(k1, k2), swap(a1, a2);
    if(n<=k1*a1)maxx=n/k1;
    else maxx=a1+(n-k1*a1)/k2;
    if(n<=a1*(k1-1)+a2*(k2-1))minn=0;
    else{
        minn=n-a1*(k1-1)-a2*(k2-1);
    }
    printf("%d %d", minn, maxx);
}