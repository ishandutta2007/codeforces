#include <bits/stdc++.h>

using namespace std;

string A[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main()
{
    int a;
    string cur;
    cin >> a >> cur;
    for (int i = 0; i < 8; ++i)
    {
        
        if (A[i].size() == cur.size())
        {
            bool valid = true;
            for (int j = 0; j < cur.size(); ++j)
            {
                if (cur[j] != '.' && A[i][j] != cur[j])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                cout << A[i] << endl;
                return 0;
            }
        }   
    }   
}