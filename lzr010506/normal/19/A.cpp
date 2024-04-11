#include<bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

bool cmp(pair<string, pair<int, ii> > p, pair<string, pair<int, ii> > q)
{
    if (p.second.first > q.second.first) return true;
    if (p.second.first < q.second.first) return false;
    if (p.second.second.first - p.second.second.second > q.second.second.first - q.second.second.second) return true;
    if (p.second.second.first - p.second.second.second < q.second.second.first - q.second.second.second) return false;
    if (p.second.second.first > q.second.second.first) return true;
    if (p.second.second.first < q.second.second.first) return false;
    return p.first < q.first;
}

int main()
{
    int n;
    cin >> n;
    map<string, pair<int, ii> > M;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        M[s] = mp(0, ii(0, 0));
    }
    for (int it = 0; it < n * (n - 1) / 2; it++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        for (int i = 0; i < sz(s1); i++)
            if (s1[i] == '-') s1[i] = ' ';
        stringstream ss1(s1);
        string name1, name2;
        ss1 >> name1 >> name2;
        for (int i = 0; i < sz(s2); i++)
            if (s2[i] == ':') s2[i] = ' ';
        int num1, num2;
        stringstream ss2(s2);
        ss2 >> num1 >> num2;
        int sc1, sc2;
        if (num1 > num2)
            sc1 = 3, sc2 = 0;
        else if (num1 == num2)
            sc1 = 1, sc2 = 1;
        else
            sc1 = 0, sc2 = 3;
        M[name1].first += sc1;
        M[name2].first += sc2;
        M[name1].second.first += num1;
        M[name1].second.second += num2;
        M[name2].second.first += num2;
        M[name2].second.second += num1;
    }
    vector<pair<string, pair<int, ii> > > v;
    for (map<string, pair<int, ii> >::iterator it = M.begin(); it != M.end(); it++)
    {
        v.pb(mp(it->first, it->second));
    }
    sort(all(v), cmp);
    vector<string> res;
    for (int i = 0; i < sz(v) / 2; i++)
        res.pb(v[i].first);
    sort(all(res));
    for (int i = 0; i < sz(res); i++)
        cout << res[i] << "\n";
    return 0;
}