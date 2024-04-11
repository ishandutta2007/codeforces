#include<bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; 
    cin >> T;
    while(T --)
    {
        int n, x; 
        cin >> n >> x;
        multiset<ll> s;
        rep(i, 1, n)
        {
        	int l; 
        	cin >> l; 
        	s.insert(l);
        }
        int cnt = 0;
        auto it = s.begin();
        while(it != s.end()) 
        {
            auto it1 = s.find(x * (*it));
            if(it1 != s.end()){s.erase(it1); it ++;}
            else cnt ++, it ++;
        }
        cout << cnt << '\n';
    }
}