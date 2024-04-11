# include <iostream>
# include <cstdio>
using namespace std;

# define Mod 1000000007LL

long long a[]={1, 3, 15, 133, 2025, 37851, 1030367, 36362925};

int n;
int main()
{
    cin >> n;
    if(n%2==0)
    {
        cout<<0<<endl;
        return 0;
    }
    long long ans=a[(n-1)/2];
    for(int i=2;i<=n;i++)
    {
        ans*=i;
        ans%=Mod;
    }
    cout << ans << endl;
    return 0;
}