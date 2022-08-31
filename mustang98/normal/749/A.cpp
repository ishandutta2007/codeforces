#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

vector<int> ans;

int main()
{
    //ifstream cin("input.txt");
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        while(n)
        {
            ans.push_back(2);
            //cout << 2 << ' ';
            n-=2;
        }
    }
    else
    {
        ans.push_back(3);
        //cout << 3 << ' ';
        n-=3;
        while(n)
        {
            ans.push_back(2);
            //cout << 2 << ' ';
            n-=2;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}