#include <bits/stdc++.h>
using namespace std;
char v[103];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,i,j,t;
    cin>>t;
    while(t--)
    {
        long long g,b;
        cin>>n>>g>>b;
        if(g>=b)
        {
            cout<<n<<'\n';
            continue;
        }
        long long cat=(n+1)/2;
        long long k=0;
        k=(cat-1LL)/g+1LL;
        long long catsc=k*g-cat;
        cout<<max(k*g+(k-1LL)*b-catsc,n)<<'\n';
    }
    return 0;
}