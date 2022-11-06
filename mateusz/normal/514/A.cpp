#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long n, s;
    cin >> n;
    s = n;
    vector<int> digits;
    while(n > 0)
    {
        digits.push_back(n % 10);
        n /= 10;
    }
    int start = digits.size() - 1;
    if(digits[start] == 0 || digits[start] == 9)
        start--;
    for(int i = 0; i <= start; i++)
        if(digits[i] > 9 - digits[i]) digits[i] = 9 - digits[i];
    
    for(int i = digits.size() - 1; i >= 0; i--)
        cout << digits[i];
    return 0;
}