#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int cnt = 0;
	set <char> st = {'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'};
	for(int i = 0; i < s.size(); i++)
    {
        if(st.find(s[i]) != st.end())
        {
            cnt++;
        }
    }
    cout << cnt;
	return 0;
}