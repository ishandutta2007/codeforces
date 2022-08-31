#include<iostream>

using namespace std;

const int MaxN=35;

int n;
int v[MaxN][MaxN];
int SumC[MaxN],SumR[MaxN];

int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            cin>>v[i][j];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            SumR[i]+=v[i][j];
            SumC[i]+=v[j][i];
        }
    int ans=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (SumC[i]>SumR[j]) ++ans;
    cout<<ans<<endl;
    return 0;
}