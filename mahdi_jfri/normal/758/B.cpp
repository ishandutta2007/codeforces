#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (a & (1 << b))
const int maxn = 1e5 + 20;
int res[10];
map<char , int> mp;
vector<int> r , b , y , c;
char ch[20];
int main()
{
    mp['R'] = 0;
    mp['B'] = 1;
    mp['Y'] = 2;
    mp['G'] = 3;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != '!')
            ch[(i + 1) % 4] = s[i];
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '!')
        {
            res[mp[ch[(i + 1) % 4]]]++;
        }
    }
    cout << res[0] << " " << res[1] << " " << res[2] << " " << res[3];
}