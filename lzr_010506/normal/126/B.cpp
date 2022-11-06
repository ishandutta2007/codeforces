#include <bits/stdc++.h>
using namespace std;
int Z[2000010];
void search(string text)
{
    string str = text;
    int n = str.length();
    int L, R, k;
    L = R = 0;
    for (int i = 1; i < n; i ++)
        if (i > R)
        {
            L = R = i;
            while (R < n && str[R - L] == str[R]) R ++;
            Z[i] = R - L;
            R --;
        }
        else
        {
            k = i - L;
            if (Z[k] < R - i + 1) Z[i] = Z[k];
            else
            {
                L = i;
                while (R < n && str[R - L] == str[R]) R ++;
                Z[i] = R - L;
                R --;
            }
        }
}



int main()
{
	string text;
	cin >> text;
    search(text);
    int maxz = 0, res = 0;
    int n = text.size();
    for (int i = 1; i < n; i ++)
    {
        if (Z[i] == n - i && maxz >= n - i) { res = n - i; break; }
        maxz = max(maxz, Z[i]);
    }
    if(res == 0) {cout << "Just a legend"; return 0;}
    for(int i = 0; i < res; i ++)
        cout << text[i];
    return 0;
}