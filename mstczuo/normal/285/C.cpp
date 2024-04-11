# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cmath>
using namespace std;

int n,a[300010];

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=abs((long long)(a[i])-(long long)(i));
    cout << ans << endl;
    return 0;
}