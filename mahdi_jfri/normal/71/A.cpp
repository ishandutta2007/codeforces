
 #include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        if(s.size() > 10)
            cout << s[0] << s.size()-2 << s[s.size()-1] << endl;
        else
            cout << s << endl;
    }
}