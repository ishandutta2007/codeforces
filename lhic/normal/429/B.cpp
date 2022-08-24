#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <iomanip>
#include <ctime>


typedef long long ll;
typedef long double ld;


using namespace std;

typedef pair<int,int> pii;


const int MAX_N=1010;


int n;

int arr[MAX_N][MAX_N];

ll d1[MAX_N][MAX_N];

ll d2[MAX_N][MAX_N];

ll d3[MAX_N][MAX_N];

ll d4[MAX_N][MAX_N];



int m;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin>>n>>m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            scanf("%d",&arr[i][j]);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            d1[i][j]=max(d1[i-1][j],d1[i][j-1])+arr[i][j];
    for (int i=1;i<=n;++i)
        for (int j=m;j>=1;--j)
            d2[i][j]=max(d2[i-1][j],d2[i][j+1])+arr[i][j];
    for (int i=n;i>=1;--i)
        for (int j=1;j<=m;++j)
            d3[i][j]=max(d3[i+1][j],d3[i][j-1])+arr[i][j];
    for (int i=n;i>=1;--i)
        for (int j=m;j>=1;--j)
            d4[i][j]=max(d4[i+1][j],d4[i][j+1])+arr[i][j];

    ll ans=0;

    for (int i=2;i<n;++i)
        for (int j=2;j<m;++j)
        {
            ans=max(ans,d1[i][j-1]+d4[i][j+1]+d3[i+1][j]+d2[i-1][j]);
            ans=max(ans,d1[i-1][j]+d4[i+1][j]+d3[i][j-1]+d2[i][j+1]);
        }
    cout<<ans;


    return 0;
}