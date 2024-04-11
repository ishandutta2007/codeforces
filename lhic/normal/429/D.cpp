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


const int MAX_N=101000;


int n;

int arr[MAX_N];


int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>arr[i];
    int ans=1000000000;
    for (int i=1;i<n;++i)
    {
        int sum=0;
        for (int j=i;j<i+500 && j<n;++j)
        {
            sum+=arr[j];
            if (abs(sum)<10010)
                ans=min(ans,sum*sum+(j-i+1)*(j-i+1));
        }
    }
    cout<<ans;
    return 0;
}