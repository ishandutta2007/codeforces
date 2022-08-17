#include <bits/stdc++.h>

#define S second
#define F first

using namespace std;
typedef long long ll;


int main()
{
    int a, b, c;
    int m[1000], m1[1000];
    int n;
    cin >> n;
    int s1= 0, s2=0;
    for(int i = 0; i < n;i++)
    {
        cin >> a >> b;
        if (a > b) s1++;
        if (a < b) s2++;
    }
    if (s1 > s2) cout << "Mishka";
    else if (s1 < s2) cout << "Chris";
    else cout << "Friendship is magic!^^";
}