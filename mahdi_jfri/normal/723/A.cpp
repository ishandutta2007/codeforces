#include<bits/stdc++.h>
using namespace std;
#define ll long long
int _min = 1e6;
ll dp;
int main()
{
    int x[3];
    for(int i = 0; i < 3; i++)
        cin >> x[i];
    for(int i = 0; i < 1000; i++)
    {
        dp = 0;
        for(int j = 0; j < 3; j++)
            dp += abs(x[j] - i);
        _min = min((int)dp,_min);
    }
    cout << _min;
}