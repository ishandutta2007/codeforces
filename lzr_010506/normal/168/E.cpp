#include <bits/stdc++.h>
using namespace std;

int check(long long a,long long b)
{
    if(a == 0) return 0;
    if(check(b % a, a))
    {
        b /= a;
        return !((b % (a + 1)) & 1);
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --)
    {
        long long a,b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(check(a, b)) cout << "First" << endl;
        else cout << "Second" << endl;
    }
}