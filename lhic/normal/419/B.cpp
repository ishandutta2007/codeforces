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

const int MAX_N=201000;


typedef pair<int,int> pii;

int n,k,m;


bool ap[MAX_N];


vector<pii> eve;

int res[MAX_N];

bool bad[MAX_N];

vector<int> ans;

bool op[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    int now=0;
    int mm=0;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        char c;
        int a;
        cin>>c>>a;
        if (c=='+')
        {
            ap[a]=true;
            op[a]=true;
            eve.push_back(pii(0,a));
        }
        else
        {
            ap[a]=true;
            if (!op[a])
            {
                ++mm;
            }
            else
                op[a]=false;
            eve.push_back(pii(1,a));
        }
    }
    now=mm;
    for (int i=0;i<m;++i)
    {
        int a=eve[i].second;
        if (eve[i].first==0)
        {
            if (i>0 && eve[i-1].second!=a)
                bad[a]=true;
            if (now>0)
                bad[a]=true;
            now+=1;
        }
        else
        {
            now-=1;
            if (now>0)
                bad[a]=true;
        }
    }
    for (int i=1;i<=n;++i)
    {
        if (ap[i] && !op[i] && eve[m-1].second!=i)
            bad[i]=true;
    }
    for (int i=1;i<=n;++i)
        if (!bad[i])
            ans.push_back(i);
    cout<<ans.size()<<"\n";
    for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";
    return 0;
}