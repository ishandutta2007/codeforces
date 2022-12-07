#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll b[4], a = 0;
    for(int i = 0; i < 3; i ++) cin>>b[i], a += b[i];
    a --;
    for(int i = 0; i < 3; i ++)
        for(int j = i + 1; j < 3; j ++)
            if(abs(b[i] - b[j]) % 2 == 0)
        		a = min(a, max(b[i], b[j]));
    cout<<a;
    return 0;
}