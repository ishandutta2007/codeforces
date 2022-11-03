#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+20;
bool check(int n)
{
    map<int,int>a;
    while(n > 0)
    {
        if(++a[n%10] > 1)
            return 0;
        n/=10;
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    n++;
    while(!check(n))
    {
        n++;
    }
    cout << n;
}