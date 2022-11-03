#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 20;
string s , password;
int res;
int main()
{
    int n;
    cin >> n;
    cin >> s >> password;
    for(int i = 0; i < s.size(); i++)
    {
        int a = s[i] - '0';
        int b = password[i] - '0';
        if(a < b)
            swap(a , b);
        res += min(abs(a - b) , (10 - a + b));
    }
    cout << res;
}