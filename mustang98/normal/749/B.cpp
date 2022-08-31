#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

set<pair<int, int> > m;

int main()
{
    //ifstream cin("input.txt");
    int x[3];
    int y[3];
    for (int i = 0; i < 3; i++)
    {
        cin>>x[i]>>y[i];
    }

    m.insert(make_pair(x[2] + (x[1] - x[0]), y[2] + (y[1] - y[0])));
    m.insert(make_pair(x[2] + (x[0] - x[1]), y[2] + (y[0] - y[1])));
    m.insert(make_pair(x[1] + (x[0] - x[2]), y[1] + (y[0] - y[2])));
    m.insert(make_pair(x[1] + (x[2] - x[0]), y[1] + (y[2] - y[0])));
    m.insert(make_pair(x[0] + (x[1] - x[2]), y[0] + (y[1] - y[2])));
    m.insert(make_pair(x[0] + (x[2] - x[1]), y[0] + (y[2] - y[1])));
    set<pair<int, int> > :: iterator it = m.begin();
    cout << m.size() << endl;
    while(it != m.end())
    {
        cout << it->first << ' ' << it->second << endl;
        it++;
    }
    return 0;
}