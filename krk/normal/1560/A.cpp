#include <bits/stdc++.h>
using namespace std;

vector <int> seq;

bool Dislike(int x)
{
    if (x % 3 == 0 || x % 10 == 3) return true;
    return false;
}

int main()
{
    for (int i = 1; seq.size() < 1000; i++)
        if (!Dislike(i)) seq.push_back(i);
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        cout << seq[n - 1] << endl;
    }
    return 0;
}