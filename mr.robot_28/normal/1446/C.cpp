#include<bits/stdc++.h>
using namespace std;
pair <int, int> funct(vector <int> a, int i = 30)
{
    if(a.size() == 0)
    {
        return {0, 0};
    }
    if(i == -1)
    {
        return {a.size(), 1};
    }
    vector <int> b, c;
    for(int j = 0; j < a.size(); j++)
    {
        if(a[j] & (1 << i))
        {
            b.push_back(a[j]);
        }
        else
        {
            c.push_back(a[j]);
        }
    }
    pair <int, int> t1 = funct(b, i - 1);
    pair <int, int> t2 = funct(c, i - 1);
    pair <int, int> t;
    t.first = max(t1.first + t2.second, t1.second + t2.first);
    t.second = max(t1.second, t2.second);
    return t;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair <int, int> ans;
    ans = funct(a);
    cout << n - max(ans.first, ans.second);
	return 0;
}