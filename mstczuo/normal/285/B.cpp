# include <iostream>
# include <cstdio>
using namespace std;

int n,s,t;
int a[120000];
int main()
{
    cin >> n >> s >> t;
    int ans=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    while( s!=t )
    {
        ans++;
        s=a[s];
        if(ans>n)
        {
            ans=-1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}