#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define DB(x) cout << #x << " " << x << endl
#define MP make_pair
#define wait system("pause")

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MAXN = (int)1e5 + 10;

int L[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int64 n; cin >> n;
    if (n & 1)
       cout << -(n + 1) / 2 << endl;
    else
        cout << n / 2 << endl;
    
//    wait;
    return 0;
}