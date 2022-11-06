#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6;
ll n;
string s;
map<string, int> m;
int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    cin >> n;
    for (int i = 0; i <n; i++)
    {
        cin >> s;
        if (m[s] == 0)
            cout << "OK"<<"\n";
        else
            cout << s << m[s]<<"\n";
        m[s]++;
    }
    return 0;
}