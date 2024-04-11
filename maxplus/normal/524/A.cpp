#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

const double EPS = 0.00001;

bool mfind(vector<int> a, int val)
{
    for (int p = 0; p < a.size(); p++)
        if (a[p] == val)
            return true;
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    map<int, vector<int> > a;
    for (int i = 0; i < n; i++)
    {
        int l,r;
        cin >> l >> r;
        if (a.find(l) == a.end())
        {
            a[l] = vector<int>();
        }
        if (a.find(r) == a.end())
        {
            a[r] = vector<int>();
        }
        a[l].push_back(r);
        a[r].push_back(l);
    }
    for (auto i = a.begin(); i != a.end(); i++)
    {
        cout << i->first << ": ";
        vector<int> ans;
        for (auto j = a.begin(); j != a.end(); j++)
        {
            if (i == j)
                continue;
            if (mfind(i->second, j->first))///if they're friends
                continue;
            set<int> s;
            for (int c = 0; c < i->second.size(); c++)
                s.insert(i->second[c]);
            for (int c = 0; c < j->second.size(); c++)
                s.insert(j->second[c]);
            //cout << "#@@@" << i->second.size() << ' ' << j->second.size() << ' ' << s.size() << "@@@#" << ' ';
            int amount = i->second.size() + j->second.size() - s.size();
            if ((double)amount * 100 / i->second.size() + EPS >= k)
            {
                ans.push_back(j->first);
            }
        }
        sort(ans.begin(), ans.end());
        if (ans.size() == 0)
            cout << 0;
        else
        {
            cout << ans.size() << ' ';
            for (int c = 0; c < ans.size(); c++)
                cout << ans[c] << ' ';
        }
        cout << endl;
    }
    return 0;
}