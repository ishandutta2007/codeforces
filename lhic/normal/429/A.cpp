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



vector<int> eds[MAX_N];


vector<int> res;

int was[MAX_N];

void DFS(int v,int c1,int c2)
{
    was[v]=true;
    if (arr[v]^c1)
    {
        res.push_back(v);
        c1^=1;
    }
    for (int i=0;i<eds[v].size();++i)
    {
        if (!was[eds[v][i]])
            DFS(eds[v][i],c2,c1);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i=0;i<n-1;++i)
    {
        int a,b;
        cin>>a>>b;
        --a;
        --b;
        eds[a].push_back(b);
        eds[b].push_back(a);
    }
    for (int i=0;i<n;++i)
        cin>>arr[i];
    for (int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        arr[i]^=x;
    }
    DFS(0,0,0);
    cout<<res.size()<<"\n";
    for (int i=0;i<res.size();++i)
    {
        cout<<res[i]+1<<"\n";
    }

    return 0;
}