#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
bool isprime(int a)
{
    for(int i = 2; i * i <= a; i++)
        if(a % i == 0)
            return 0;
    return 1;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= 1e3; i++)
    {
        if(!isprime(n * i + 1))
        {
            cout << i << endl;
            return 0;
        }
    }
}