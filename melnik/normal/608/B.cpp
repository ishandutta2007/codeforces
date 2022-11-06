#include <iostream>
#include <fstream>
#include <stdio.h>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 2e5 + 500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int pref0[maxn],pref1[maxn];

int main()
{
    string a,b;
    cin>>a>>b;

    int sum=0;
    for (int i=0;i<b.size();i++)
    {

        if (b[i]=='0')
        {

            sum++;

        }   pref0[i]=sum;

    }
    sum=0;
    for (int i=0;i<b.size();i++)
    {

        if (b[i]=='1')
        {
            sum++;

        } pref1[i]=sum;

    }
    ll ans=0;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]=='0')
        {
            if (i>0)
            ans+=pref1[b.size()-a.size()+i]-pref1[i-1];
            else
            ans+=pref1[b.size()-a.size()];
        }
        else
        {
            if (i>0)
            ans+=pref0[b.size()-a.size()+i]-pref0[i-1];
            else
            ans+=pref0[b.size()-a.size()];
        }
    }
    cout<<ans;
  //  cout << "Hello world!" << endl;
    return 0;
}