#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p, q;
    string s;
    cin >> n >> p >> q;
    cin >> s;
   	for(int i = 0; i < 200; i ++)
    {
    	if(p * i > n) break;
    	if((n - i * p) % q == 0)
    	{
    		int x = (n - i * p) / q;
    		cout << i + x << endl;
    		for(int j = 0; j < i; j ++) cout << s.substr(j * p, p) << endl;
    		for(int j = 0; j < x; j ++) cout << s.substr(i * p + j * q, q) << endl;
    		return 0;
    	}
    }
    cout << -1 << endl;
    return 0;
}