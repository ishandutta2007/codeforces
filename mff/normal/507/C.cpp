#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long int64;

map<int64, bool> M;
int64 ex;

int64 solve(int64 n, int64 m, int64 lv)
{
    //cout << n << endl;
    //system("pause");
    int64 ans = 0;
    if (n == ex) ans = 0;
    else if (m){
       int64 nx = n << 1;
       if (M[nx]) ans =  1 + solve(nx, 0, lv - 1);
       else ans = (1LL << lv) + solve(nx + 1, 1, lv - 1);
    }
    else{
       int64 nx = (n << 1) + 1;
       if (M[nx]) ans =  1 + solve(nx, 1, lv - 1);
       else ans = (1LL << lv) + solve(nx - 1, 0, lv - 1);
    }
    //cout << n << " " << m << " " << lv << " " << ans << endl;
    return ans;
}

int main()
{
    
    int64 n, h;
    cin >> h >> n;
    ex = (1LL << h) - 1 + n;
    n = ex;
    //cout << ex << endl;
    while (n)
    {
          //cout << n << endl;
          //system("pause");
          M[n] = true;
          n >>= 1;
    }
    cout << solve(1, 1, h) << endl;
    
    //system("pause");
}