#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int _min[4] , _max[4] , res[4];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < 3; i++)
        cin >> _min[i] >> _max[i];
    while(_min[0] + _min[1] + _min[2] < n)
    {
        if(_min[0] + 1 <= _max[0])
            _min[0]++;
        else if(_min[1] + 1 <= _max[1])
            _min[1]++;
        else
            _min[2]++;
    }
    cout << _min[0] << " " << _min[1] << " " << _min[2];
}