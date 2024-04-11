#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;


int main()
{
    string s1, s2, t;
    cin >> s1 >> s2 >> t;
    for (int i = 0; i < t.size(); i++)
    {
       // cout <<i << endl;
        bool r = false;
        for (int j = 0; j < s1.size(); j++)
        {
            if (s1[j] == t[i])
         {
             cout << s2[j];
           r = true;
          }  if (s1[j] - t[i] == 'a' - 'A')
              {
                  cout << char(s2[j] +'A' - 'a');
                r = true;
              }
        }
        if (!r)
            cout << t[i];

    }
    return 0;
}