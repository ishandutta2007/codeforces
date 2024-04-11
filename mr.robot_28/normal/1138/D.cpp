#include <iostream>
#include <cstdio>
#include<vector>
#include <cstring>
using namespace std;
int main()
{
	string s, t;
	cin >> s >> t;
	int cnt10 = 0, cnt11 = 0, cnt20 = 0, cnt21 = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '0')
		{
			cnt10++;
		}
		else
		{
			cnt11++;
		}
	}
	for(int i = 0; i < t.size(); i++)
	{
		if(t[i] == '0')
		{
			cnt20++;
		}
		else
		{
			cnt21++;
		}
	}
	vector <int> z(t.size());
    int l = 0, r = 0;
    int imax = 0;
    for(int i = 1; i < t.size(); i++)
    {
        //cout << l << " " << r << endl;
        if(i > r)
        {
        //  cout << i << " " << r << endl;
            int k = 0;
            while(k + i < t.size() && t[i + k] == t[k])
            {
                k++;
            }
            if(k != 0)
            {
                l  = i;
                r = k - 1 + i;
            }
            z[i] = k;
        }
        else
        {
            if(i + z[i - l] <= r)
            {
                z[i] = z[i - l];
            }
            else
            {
                int u = 1;
                while(u + r < t.size() && t[u + r] == t[r - i + u])
                {
                    u++;
                }
                u--;
                //cout << r << " ";
                z[i] = u + r - i + 1;
                r += u;
                l = i;
            }
        }
        if(z[i] == t.size() - i)
        {
        	imax = i;
        	break;
		}
    }
    if(cnt10 >= cnt20 && cnt11 >= cnt21)
    {
    	cout << t;
    	cnt10 -= cnt20;
    	cnt11 -= cnt21;
    	string t1 = "";
    	cnt20 = 0;
    	cnt21 = 0;
    	if(imax == 0)
    	{
    		imax = t.size();
		}
    	for(int i = t.size() - imax; i < t.size(); i++)
    	{
    		t1 += t[i];
    		if(t[i] == '0')
    		{
    			cnt20++;
			}
			else
			{
				cnt21++;
			}
		}
		while(cnt10 >= cnt20 && cnt11 >= cnt21)
		{
			cout << t1;
			cnt10 -= cnt20;
			cnt11 -= cnt21;
		}
		while(cnt10 > 0)
		{
			cnt10--;
			cout << "0";
		}
		while(cnt11 > 0)
		{
			cnt11--;
			cout << "1";
		}
	}
	else
	{
		cout << s;
	}
    return 0;
}