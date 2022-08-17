#include <bits/stdc++.h>

#define S second
#define F first

using namespace std;
typedef long long ll;

vector<int> ans;

    int a = 0, b = 0, c = 0;
    int m[1000], m1[1000];
    int n, s;




int main()
{
    int kpol = 0, ans = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == -1)
            if( kpol == 0) ans++;
            else kpol--;
        else kpol+=a;


    }
    cout << ans;
}