#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
int w , res;
int main()
{
    int n , b , d;
    cin >> n >> b >> d;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a > b)
            continue;
        w += a;
        if(w > d)
            w = 0 , res++;
    }
    cout << res;
}