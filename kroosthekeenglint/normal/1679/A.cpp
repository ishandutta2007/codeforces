#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    ios::sync_with_stdio(false);
    int zu;
    cin>>t;
    for (zu=0;zu<t;zu++)
    {
        long long n;
        cin>>n;
        if ((n%2==1)||(n==2))
        {
            cout<<"-1\n";
        }
        else
        {
            n/=2;
            cout<<(n+2)/3<<" "<<n/2<<"\n";
        }
    }
    return 0;
}