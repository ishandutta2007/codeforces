#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl
#define wait system("pause")

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAXN = (int)1e5 + 10;

int main()
{
    int n, x;
    cin >> n >> x;
    
    int ans = 0;
    int last = 1;
    
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        last += x * ((l - last) / x);
        ans += r - last + 1;
        last = r + 1;
    }
    
    cout << ans << endl;
    
    //wait;
}