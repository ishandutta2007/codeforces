#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll res1 , res2 , res3 , a , b , c , n , _min = 9e18;
int main()
{
    cin >> n >> a >> b >> c;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            for(int z = 0; z < 10; z++)
            {
                if((i + 2 * j + 3 * z + n) % 4 == 0)
                {
                    _min = min(_min , i * a + b * j + c * z);
                }
            }
    cout << _min;
}