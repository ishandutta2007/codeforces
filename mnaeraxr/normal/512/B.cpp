#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string.h>
#include <cstdio>

#define wait system("pause")
#define MP make_pair

using namespace std;

const int MAXN = (int)1e5 + 10;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

vi L, C;

map<int, int> M;

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

void insert(int v, int c)
{
    if (M.count(v) == 0) M[v] = c;
    else{
        int &val = M[v];
        val = min( val , c);
    }
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int v; cin >> v;
        L.push_back(v);
    }
    for (int i = 0; i < n; ++i)
    {
        int v; cin >> v;
        C.push_back(v);
    }

    for (int i = 0; i < n; ++i)
    {
        insert( L[i], C[i] );
        
        for (map<int,int>::iterator it = M.begin(); it != M.end(); ++it)
        {
            insert( gcd(it->first, L[i]), it->second + C[i]);
        }
    }

    if (M.count( 1 ) == 0)
        cout << -1 << endl;
    else
        cout << M[1] << endl;
}