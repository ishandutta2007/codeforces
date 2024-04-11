#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e4 + 20;
ll res , u;
int main()
{
    int n , i = 1 , m;
    cin >> n >> m;
    while(n)
    {
        if(!(i % m))
            n++;
        i++;
        n--;
    }
    cout << i - 1 << endl;
}