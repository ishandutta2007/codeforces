#include <iostream>
#include <cstdio>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;

int n;
map <int, int> M;
deque <int> D;

void Check()
{
     int cur = M.begin()->first;
     M[cur]--; D.push_back(cur);
     while (true) {
           if (M[cur + 1]) {
                     M[cur + 1]--; D.push_front(cur + 1);
           } else return;
           if (M[cur + 1]) {
                     M[cur + 1]--; D.push_back(cur + 1);
           } else return;
           while (M[cur]) {
                 M[cur]--; D.push_back(cur);
                 if (M[cur + 1]) {
                           M[cur + 1]--; D.push_back(cur + 1);
                 } else return;
           }
           cur++;
     }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        M[tmp]++;
    }
    Check();
    if (D.size() < n || abs(D.front() - D.back()) != 1) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}