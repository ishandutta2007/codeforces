#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
int n;
int arr[200010];
int main()
{
    scanf("%d", &n);
    if(n%2==0){
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i=1; i<=n; i++){
        arr[2*i-1]=2*i-1;
    }
    for(int i=1; i<=n/2+1; i++){
        arr[n+2*i-1]=2*i;
    }
    for(int i=n/2+2; i<=n; i++){
        arr[(i-n/2-1)*2]=2*i;
    }
    for(int i=1; i<=2*n; i++)printf("%d ", arr[i]);
}