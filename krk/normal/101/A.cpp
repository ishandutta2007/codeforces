#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxl = 26;

string s;
int k;
int cnt[Maxl];
bool del[Maxl];
priority_queue <pair <int, int> > Q;
int res;

int main()
{
    cin >> s >> k;
    for (int i = 0; i < s.length(); i++) cnt[s[i]-'a']++;
    for (int i = 0; i < Maxl; i++)
       if (cnt[i]) Q.push(make_pair(-cnt[i], i));
    while (!Q.empty() && -Q.top().first <= k) {
          k += Q.top().first; del[Q.top().second] = true; Q.pop();
    }
    for (int i = 0; i < Maxl; i++)
       if (cnt[i] && !del[i]) res++;
    cout << res << endl;
    for (int i = 0; i < s.length(); i++)
       if (!del[s[i]-'a']) printf("%c", s[i]);
    cout << endl;
    return 0;
}