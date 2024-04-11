#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll _max = 1;
int res = 0;
bool x;
char check[10] = { 'A', 'E', 'I', 'O', 'U' ,'Y'};
int main()
{
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        res++;
        for(int j = 0; j < 6; j++)
        {
            if(s[i] == check[j])
            {
                _max = max((ll) res , _max);
                res = 0;
                break;
            }
        }
        if(i + 1 == s.size())
        {
            res++;
            _max = max((ll)res , _max);
        }
    }
    cout << _max;
}