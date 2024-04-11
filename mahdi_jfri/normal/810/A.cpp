#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
double n , k , res , avg;
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        avg += a;
    }
    double nn = n;
    while(round(avg / n) < k)
    {
        n++;
        avg += k;
    }
    cout << n - nn;
}