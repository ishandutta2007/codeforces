#include<bits/stdc++.h>

using namespace std;

#define pb push_back
const int maxi =1e6+10;
int a[maxi];
vector<int> v[maxi];
int n,m;
pair<int,int> b[maxi];
long long s[maxi];

int main()
{
    cin>>n>>m;

    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&b[i].first,&b[i].second);
    }

    sort(b+1,b+m+1);

    for (int i=1;i<=m;i++)
        s[i] = s[i-1] + b[i].second;

    for (int i=1;i<=n;i++)
    {
        int l = 0;
        int r = m+1;

        while(l<r-1)
        {
            int mid = (l+r)>>1;
            if (b[mid].first<=a[i]) l = mid; else r= mid;
        }

        printf("%lld ", s[l]);
    }
    printf("\n");
    return 0;
}