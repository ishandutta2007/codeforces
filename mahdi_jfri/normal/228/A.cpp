#include<bits/stdc++.h>
using namespace std;
int a;
set<int>st;
int main()
{
    for(int i = 0; i < 4; i++)
    {
        cin >> a;
        st.insert(a);
    }
    cout <<4-st.size();
}