#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

map<string, pair<int, int>> game;
int main()
{
    int n, score[1005], _max = 0;
    string name[1005], max_player;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name[i] >> score[i];
        game[name[i]].first += score[i];
    }
    for (auto i : game)
    {
        _max = max(i.second.first, _max);
        i.second.second = 0;
    }
    for (int i = 0; i < n; i++)
    {
        game[name[i]].second += score[i];
        if (game[name[i]].first >= _max && game[name[i]].second >= _max)
        {
            cout << name[i] << '\n';
            return 0;
        }
    }
}