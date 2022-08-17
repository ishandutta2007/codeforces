#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

vector<pair<int, int> > v;
vector<pair<int, int> > ch;
vector<pair<int, int> > nech;
vector<pair<int, int> > dubl;
set<int> chset;
set<int> nechset;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.S < b.S;
}

int main()
{
    //ifstream cin("input.txt");
    int n, m, a;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        v.push_back(make_pair(a, i));
    }
    sort(v.begin(), v.end());
    //for (int i = 0; i < n; i++) cout << v[i].F;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            if (v[i].F == v[i - 1].F)
            {
                dubl.push_back(v[i]);
                continue;
            }
        }
        if (v[i].F % 2 == 0)
        {
            ch.push_back(v[i]);
            chset.insert(v[i].F);
        }
        else
        {
            nech.push_back(v[i]);
            nechset.insert(v[i].F);
        }
    }

    //cout << ch.size() << endl;
    //cout << nech.size() << endl;
    //cout << dubl.size() << endl;

    while(ch.size() > n/2)
    {
        dubl.push_back(ch.back());
        ch.pop_back();
    }

    while(nech.size() > n/2)
    {
        dubl.push_back(nech.back());
        nech.pop_back();
    }

    int needch = n / 2 - ch.size();
    int neednech = n / 2 - nech.size();
    int curd = 0;
    int maxch = 0;
    int ans = dubl.size();
    for (int i = 0; i < needch; i++)
    {
        while(true)
        {
            maxch += 2;
            if (chset.count(maxch) == 0) break;
        }
        if (maxch > m)
        {
            cout << "-1";
            return 0;
        }
        dubl[curd].F = maxch;
        curd++;
    }
  //  cout << "AAAAA";
    int maxnech = -1;
    for (int i = 0; i < neednech; i++)
    {
        while(true)
        {
            maxnech += 2;
            if (nechset.count(maxnech) == 0) break;
        }
        if (maxnech > m)
        {
            cout << "-1";
            return 0;
        }
        dubl[curd].F = maxnech;
        curd++;
    }

    cout << ans << endl;
    dubl.insert(dubl.end(), ch.begin(), ch.end());
    dubl.insert(dubl.end(), nech.begin(), nech.end());

    sort(dubl.begin(), dubl.end(), comp);

    for (int i = 0; i  < dubl.size(); i++) printf("%d ", dubl[i].F);
    return 0;
}