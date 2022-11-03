#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define time tttt
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int y;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        string s;
        cin >> t >> s;
        if(y != 0 && s == "North")
        {
            y -= t;
        }
        else if(y != 20000 && s == "South")
        {
            y += t;
        }
        else if(y == 0 || y == 20000)
        {
            cout << "NO";
            return 0;
        }
        if(y < 0 || y > 20000)
        {
            cout << "NO";
            return 0;
        }
    }
    if(y == 0)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}