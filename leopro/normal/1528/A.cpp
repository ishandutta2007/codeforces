// Alex2184 submission https://codeforces.com/contest/1528/submission/117255092

#pragma comment(linker, "/STACK:1000000000")
#include <map>
#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string>
#include <deque>
#include <math.h>
using namespace std;


pair<long long, long long> maxx(long long a, vector<pair<long long, long long>>& num, vector<set<long long>>& pathfind) {
    long long m1 = num[a].first;
    long long m2 = num[a].second;
    pair<long long, long long> ans;
    for (auto elem : pathfind[a]) {
        pair<long long, long long> temp = maxx(elem, num, pathfind);
        long long var1 = abs(m1 - num[elem].first) + temp.first;
        long long var2 = abs(m1 - num[elem].second) + temp.second;
        if (var2 > var1) var1 = var2;
        ans.first += var1;

        var1 = abs(m2 - num[elem].first) + temp.first;
        var2 = abs(m2 - num[elem].second) + temp.second;
        if (var2 > var1) var1 = var2;
        ans.second += var1;
    }

    return ans;



}


int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    long long q;
    cin >> q;
    for (long long w = 0; w < q; ++w) {
        long long n;
        cin >> n;
        vector<pair<long long, long long>> num;
        vector<pair<long long, long long>> alternate(n + 10);
        pair<long long, long long> t(0, 0);
        num.push_back(t);
        alternate[0] = t;
        for (int i = 0; i < n; ++i) {
            pair<long long, long long> z;
            cin >> z.first;
            cin >> z.second;
            num.push_back(z);

        }
        vector<set<long long>> pathfind(n + 10);
        for (long long i = 0; i < n - 1; ++i) {
            long long a, b;
            cin >> a;
            cin >> b;
            pathfind[a].insert(b);
            pathfind[b].insert(a);
        }
        vector<long long> bef(n + 10);
        vector<long long> chosen(n + 10);
        long long ans = 0;
        deque<long long> yetyet;
        for (auto elem : pathfind[1]) {
            yetyet.push_back(elem);
            pathfind[elem].erase(1);
            bef[elem] = 1;
        }
        while (yetyet.size() > 0) {
            long long l = yetyet.front();
            yetyet.pop_front();
            for (auto elem : pathfind[l]) {
                yetyet.push_back(elem);
                pathfind[elem].erase(l);
                bef[elem] = l;
            }



        }
        pair<long long, long long> answer = maxx(1, num, pathfind);
        if (answer.second > answer.first) answer.first = answer.second;
        cout << answer.first << "\n";

    }
    return 0;
}