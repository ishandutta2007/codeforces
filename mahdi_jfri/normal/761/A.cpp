#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int main()
{
    int a , b;
    cin >> a >> b;
    if(abs(a - b) <= 1 && (a || b))
        cout << "YES";
    else
        cout << "NO";
}