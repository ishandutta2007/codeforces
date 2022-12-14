#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


map<int, int> MAP;
int n, k, tmp;



int main()
    {
    FAST;

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        {
        cin >> tmp;
        MAP[tmp] = i;
        }

    if (k > MAP.size())
        {
        cout << "NO";
        return 0;
        }

    cout << "YES" << endl;

    int i = 0;
    for (map<int, int>::iterator it = MAP.begin(); i < k; i++, it++)
        {
        cout << it->second << " ";
        }



    return 0;
    }