#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    int k;
    cin >> a >> k;
    bool f = false;
    int count = 0, count1 = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == '*')
        {
            count++;
            count1++;
            f = true;
        }
        else if(a[i] == '?')
        {
            count++;
        }
    }
    if(k >= a.size() -  2 * count && (k <= a.size() - count + count1 || f))
    {
        if(k <= a.size() - count)
        {
            int re = a.size() - count - k;
            for(int i = 0; i < a.size(); i++)
            {
                if((a[i] == '?' || a[i] == '*') && re > 0)
                {
                    re--;
                    a[i - 1] = '*';
                    //cout << a[i - 1];
                }
            }
            for(int i = 0; i < a.size(); i++)
            {
                if(a[i] != '*' && a[i] != '?')
                {
                    cout << a[i];
                }
            }
        }
        else
        {
            int re = k - a.size() + count;
            for(int i = 0; i < a.size(); i++)
            {
                if(a[i] != '*' && a[i] != '?')
                {
                    cout << a[i];
                }
                else if(a[i] == '*')
                {
                    for(; re > 0; re--)
                    {
                        cout << a[i - 1];
                    }
                }
            }
        }
    }
    else
    {
        cout << "Impossible";
    }
    return 0;
}