#include <bits/stdc++.h>
using namespace std;


map<int, bool> MAP;


int n;

string text;






int main()
    {
    //cout << (1<<2);
    cin >> n;
    //int time  = GetTickCount();

    for (int i = 0; i < n; i++)
        {
        cin >> text;
        //vector<bool> curr (30, false);
        int curr = 0;
        for (int j = 0; j < text.size(); j++)
            {
            // curr[text[j]-'a'] = true;
            curr|= (1 << (text[j]-'a'));
            }
        MAP [curr] = true;
        }




    cout << MAP.size();

    return 0;
    }