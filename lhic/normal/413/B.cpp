#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <bitset>
#include <cstdlib>

typedef long long ll;
typedef long double ld;

using namespace std;

int n,k;

const int MAX_N=30000;

int ss[MAX_N];


int arr[MAX_N][20];

int rr[20];
int m;


int main()
{
    //ios_base::sync_with_stdio(false);

    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
            scanf("%d",&arr[i][j]);
    }

    for (int i=0;i<k;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        --a;
        --b;

        ++rr[b];
        ++ss[a];
    }

    for (int i=0;i<n;++i)
    {
        int res=0;
        for (int j=0;j<m;++j)
            res+=arr[i][j]*rr[j];
        printf("%d ",res-ss[i]);
    }



    return 0;
}