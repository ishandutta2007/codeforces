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
int m,mi,ma;


int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>mi>>ma;

    int a;
    cin>>a;
    int minn=a;
    int maxx=a;

    for (int i=1;i<m;++i)
    {
        cin>>a;
        minn=min(minn,a);
        maxx=max(maxx,a);
    }

    int k=(maxx==ma) + (minn==mi);
    if (maxx>ma || minn<mi)
    {
        cout<<"Incorrect";
    }
    else if (m+2-k <= n )
    {
        cout<<"Correct";
    }
    else
        cout<<"Incorrect";

    return 0;
}