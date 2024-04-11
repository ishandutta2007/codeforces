
#include <bits/stdc++.h>
using namespace std;
//#define int long long
void add(vector <pair <int, int> > &v, pair <int, int> new_)
{
    if(v.size() > 0 && v.back().first == new_.first)
    {
        v.back().second += new_.second;
    }
    else
    {
        v.push_back(new_);
    }
}
void add(vector <pair <int, int> > &v, vector <pair <int, int> > new_)
{
    while(new_.size() > 0)
    {
        add(v, new_.back());
        new_.pop_back();
    }
}
vector <pair <int, int> > del(vector <pair <int, int> > &v, int cnt)
{
    vector <pair <int, int> > res;
    while(cnt--)
    {
        res.push_back(v.back());
        v.pop_back();
    }
    return res;
}
int get_len(vector <pair <int, int> > v)
{
    int sum = 0;
    for(int i =0; i < v.size(); i++)
    {
        sum += v[i].second;
    }
    return sum;
}
bool sw = 0;
    vector <pair <int, int> > ans;
    vector <pair <int, int> > mass1, mass2;
void query(int len_x, int len_y)
{
    vector <pair <int, int> > x1 = del(mass1, len_x);
    vector <pair <int, int> > y1 = del(mass2, len_y);
    int sum1 = get_len(x1);
    int sum2 = get_len(y1);
    if(sw)
    {
        swap(sum1, sum2);
    }
    ans.push_back({sum1, sum2});
    add(mass1, y1);
    add(mass2, x1);
}
signed main() {
  //  ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++)
    {
        int j = i;
        while(j < s.size() && s[i] == s[j])
        {
            j++;
        }
        mass1.push_back({s[i] - 'a', j - i});
        i = j - 1;
    }
    for(int i = 0; i < t.size(); i++)
    {
        int j = i;
        while(j < t.size() && t[i] == t[j])
        {
            j++;
        }
        mass2.push_back({t[i] - 'a', j - i});
        i = j - 1;
    }
    reverse(mass1.begin(), mass1.end());
    reverse(mass2.begin(), mass2.end());
    while(mass1.size() != 1 || mass2.size() != 1)
    {
        int m1 = mass1.size();
        int m2 = mass2.size();
        if(m1 < m2)
        {
            swap(m1, m2);
            swap(mass1, mass2);
            sw ^= 1;
        }
        int a = mass1.back().first;
        int b = mass2.back().first;
        if(a != b)
        {
            if(m2 <= 2)
            {
                if(m1 <= 3)
                {
                    query(1, 1);
                }
                else
                {
                    query(3, 1);
                }
            }
            else
            {
                query(1, 1);
            }
        }
        else
        {
            if(m2 == 1)
            {
                if(m1 <= 3)
                {
                    query(1, 0);
                }
                else
                {
                    query(3, 0);
                }
            }
            else if(m2 == 2)
            {
                if(m1 == 2)
                {
                    query(1, 0);
                }
                else
                {
                    query(2, 1);
                }
            }
            else
            {
                query(3, 2);
            }
        }
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}