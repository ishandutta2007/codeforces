#include<bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxi = 1e6 + 10;
int a[maxi];
string s;
int n;
vector<int> v[maxi];
int c1, c2, c3;

void solve()
{
    scanf("%d%d%d",&c1,&c2,&c3);

    for (int i= 1;i<=5;i++)
        scanf("%d",&a[i]);

    c1-=a[1];
    c2-=a[2];
    c3-=a[3];

    if (c1 < 0 || c2 <0 || c3<0)
    {
        printf("NO\n");
        return;
    }

    a[4]-=min(c1, a[4]);
    a[5]-=min(c2, a[5]);

    if (c3 >= a[4] + a[5]) printf("YES\n"); else printf("NO\n");
}

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}