#include <bits/stdc++.h>
using namespace std;

set<char> st;
string s;

int main()
{
    while(cin >> s)
        for(auto i : s)
            if('a' <= i && i <= 'z')
                st.insert(i);
    cout <<  st.size() << '\n';
}