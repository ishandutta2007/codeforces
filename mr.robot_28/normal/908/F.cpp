#include<bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin >> n;
    vector <pair <int, int> > mass(n);
    for(int i = 0; i < n; i++)
    {
        cin >> mass[i].first;
        char t;
        cin >> t;
        if(t == 'R')
        {
            mass[i].second = 0;
        }
        else if(t == 'B')
        {
            mass[i].second = 1;
        }
        else
        {
            mass[i].second = 2;
        }
    }
    sort(mass.begin(), mass.end());
    int j = 0;
    int ans = 0;
    for(int i = 0; i < mass.size() - 1; i++)
    {
        if(mass[i].second == 2 && mass[i + 1].second == 2)
        {
            ans += mass[i + 1].first - mass[i].first;
        }
    }
    for(int i = 0; i < mass.size(); i++)
    {
        if(mass[i].second == 2)
        {
            continue;
        }
        int j = i;
        int imin1 = -1, imin2 = -1, imax1 = -1, imax2 = -1;
        int max1 = 0;
        int max2 =0;
            while(j < mass.size() && mass[j].second != 2)
            {
                if(mass[j].second == 0)
                {
                    if(imin1 == -1)
                    {
                        imin1 = j;
                    }
                    imax1 = j;
                }
                else if(mass[j].second == 1)
                {
                    if(imin2 == -1)
                    {
                        imin2 = j;
                    }
                    imax2 = j;
                }
                j++;
            }
        if(i == 0 && j == n)
        {
            if(imin1 != -1)
            {
                ans += mass[imax1].first - mass[imin1].first;
            }
            if(imin2 != -1)
            {
                ans += mass[imax2].first - mass[imin2].first;
            }
            break;
        }
        else if(i == 0)
        {
            if(imin1 != -1)
            {
                ans += mass[j].first - mass[imin1].first;
            }
            if(imin2 != -1)
            {
                ans += mass[j].first - mass[imin2].first;
            }
        }
        else if(j == n)
        {
            if(imin1 != -1)
            {
                ans += mass[imax1].first - mass[i - 1].first;
            }
            if(imin2 != -1)
            {
                ans += mass[imax2].first - mass[i - 1].first;
            }
        }
        else
        {
            int last1 = mass[i - 1].first;
            int last2 = last1;
            int max1 = 0, max2 = 0;
            j = i;
            while(j < mass.size() && mass[j].second != 2)
            {
                if(mass[j].second == 0)
                {
                    max1 = max(max1, mass[j].first - last1);
                    last1 = mass[j].first;
                }
                else if(mass[j].second == 1)
                {
                    max2 = max(max2, mass[j].first - last2);
                    last2 = mass[j].first;
                }
                j++;
            }
            int len = mass[j].first - mass[i - 1].first;
            max1 = max(max1, mass[j].first - last1);
            max2 = max(max2, mass[j].first - last2);
            ans += min(3 * len - max1 - max2, 2 * len);
        }
        i = j - 1;
    }
    cout << ans;
	return 0;
}