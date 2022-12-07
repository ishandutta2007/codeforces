#include <bits/stdc++.h>

using namespace std;

char S[110], T[110];

void my_next(int len)
{
    for (int i = len - 1; i >= 0; --i)
    {
        if (S[i] == 'z')
        {
            S[i] = 'a';
            continue;
        }
        S[i]++;
        break;
    }
}

int main()
{
    cin >> S >> T;
    int len = strlen(S);
    my_next(len);
    bool ok = true;
    for (int i = 0; i < len && ok; ++i)
    {
        if (S[i] == T[i]) continue;
        ok = false;
    }
    if (ok)
    {
        cout << "No such string" << endl;
    }
    else{
        for (int i = 0; i < len; ++i)
            cout << S[i];
        cout << endl;
    }
}