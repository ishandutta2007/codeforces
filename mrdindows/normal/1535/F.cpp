#include<bits/stdc++.h>
using namespace std;
 
//======================
//
// Template OleschY
//
// Die Mglichkeiten der deutschen Grammatik knnen
// einen, wenn man sich darauf, was man ruhig, wenn
// man mchte, sollte, einlsst, berraschen.
// - @Gedankenbalsam
//
//======================
 
//======================
//      Output/Debug
//======================
 
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";//123123
    }
    os << "]\n";
    return os;
}
 
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p)
{
    os << "[";
    os << p.first;
    os << ", ";
    os << p.second;
    os << "]";
    return os;
}
 
#ifndef ONLINE_JUDGE
#define debug(x) cout << (#x) << " is " << (x) << endl
#else
#define debug(...) 42
#endif
 
//======================
// Solution Single testcase
//======================
 
pair<int, int> getlr(const string& st1, const string& st2)
{
    int ssize = st1.size();
    assert(st1.size() == st2.size());
    pair<int, int> borders = {-1, ssize};
    for(int l = 0; l < ssize; l++)
    {
        if(st1[l] == st2[l])
        {
            borders.first = l;
        }
        else break;
    }
    for(int r = ssize - 1; r >= 0; r--)
    {
        if(st1[r] == st2[r])
        {
            borders.second = r;
        }
        else break;
    }
    borders.first++;
    borders.second = ssize - borders.second;
    return borders;
}
 
long long nAll;
vector<pair<string, string>> in;
 
int solve()
{
    for(int i = 0; i < nAll ; ++i)
    {
        in[i].second = in[i].first;
        sort(in[i].second.begin(), in[i].second.end());
    }
    sort(in.begin(), in.end(), [](pair<string, string> const & a, pair<string, string> const & b)
    {
        return a.second < b.second || (a.second == b.second && a.first < b.first);
    });
    vector<vector<string>> strGroups;
    for(int i = 0; i < nAll; i++) {
        if (i == 0 || in[i].second != in[i - 1].second) {
            strGroups.push_back(vector<string>());
        }
        strGroups.rbegin()->push_back(in[i].first);
    }
    long long ans = 0;
    long long ans1337 = 0;
    long long ansWidthwisePairs = 0;
    
    cerr << strGroups[0][0].capacity() << ' ' << (size_t(strGroups[0][0].data()) & 127) << '\n';
    for(vector<string>& strs : strGroups) {
        long long n = strs.size();
        long long ssize = strs[0].size();
        ans1337 += 1337 * n * (nAll - n);
        ans += n * ( n - 1 );
        if (n >= 6800) {
            // check widthwise
            sort(strs.begin(), strs.end());
            for(string const& str : strs)
            {
                for(int i = 0; i < ssize; i++)
                {
                    for(int j = i + 1; j < ssize; j++)
                    {
                        string temp = str;
                        sort(temp.begin() + i, temp.begin() + j + 1);
                        if(temp[i] != str[i])
                        {
                            if(temp[j] != str[j])
                            {
                                if(binary_search(strs.begin(), strs.end(), temp))
                                {
                                    ansWidthwisePairs -= 2;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = i + 1; j < n; j++)
                {
                    auto [l, r] = getlr(strs[i], strs[j]);
                    if(r == ssize)
                        ans -= 2;
                    else
                    {
                        assert(strs[i].begin() + l <= strs[i].end() - r);
                        if(is_sorted(strs[i].begin() + l, strs[i].end() - r))
                            ans -= 1;
                        assert(strs[j].begin() + l <= strs[j].end() - r);
                        if(is_sorted(strs[j].begin() + l, strs[j].end() - r))
                              ans -= 1; ///123 1231
                    }
                }
            }
        }
    }
    long long sum = ans1337 / 2 + ans + ansWidthwisePairs / 2 ;
    cout << sum << "\n"; /// 123
    return 0;
}
 
void       input()
{
    cin >> nAll;
    in.resize(nAll);
    for(int i = 0; i < nAll; ++i)
    {
        cin >> in[i].first;
    }
    solve();
}
 
//======================
// Technical stuff
//======================
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("a.out", "w", stdout); // console output is better (in most cases)
#else
    // add i/o method of specific testing system
#endif
    input();
    return 0;
}