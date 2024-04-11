#include<bits/stdc++.h>

using namespace std;

#define pb push_back
const int maxi =1e6+10;
int a[maxi];
vector<int> v[maxi];
long long  n;

int main()
{
    cin>>n;

    for (long long  i=1;i<= maxi;i++)
    {
        long long val = (n- i*i - i - 1 );
        if (val%(2*i) == 0 && val>0)
        {
            return !printf("%lld %lld\n",i, val/(2*i));
        }

    }

    printf("NO\n");
    return 0;
}