#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e4 + 20;
const int inf = 1e8;
bool check[maxn];
vector<char>a;
bool cmp(char a , char b)
{
    return a > b;
}
int main()
{
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '1' || s[i] == '0')
        {
            s.erase(i , 1);
            i--;
            continue;
        }
        if(s[i] == '4')
        {
            s[i] = '3';
            s += "22";
            i--;
            continue;
        }
        if(s[i] == '6')
        {
            s[i] = '5';
            s += "3";
            continue;
        }
        if(s[i] == '8')
        {
            s[i] = '7';
            s += "222";
        }
        if(s[i] == '9')
        {
            s[i] = '3';
            s += "732";
        }
    }
    sort(s.begin() , s.end() , cmp);
    cout << s;
}