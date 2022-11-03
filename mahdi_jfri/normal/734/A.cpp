#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
string s;
int a , b , n;
int main()
{
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'D')
            b++;
        else
            a++;
    }
    if(a > b)
        cout << "Anton";
    else if(a == b)
        cout << "Friendship";
    else
        cout << "Danik";
}