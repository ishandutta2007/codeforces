#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define double long double
const double eps = 1e-9;
const double pi = 3.14159265;
double intersection(pair <int, int> a, pair <int, int > b)
{
    int k1 = a.first;
    int k2 = b.first;
    int b1 = a.second;
    int b2 = b.second;
    double g = b2 - b1;
    return g / (k1 - k2);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> A(n);
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int k = sqrt(n);
    k++;
    vector <vector <pair <int, int> > > SQRTCHT(k);
    vector <int> postsum(n), postfunct(n);
    for(int i = n - 1; i >= 0; i--)
    {
        postsum[i] = A[i];
        if(i != n - 1)
        {
            postsum[i] += postsum[i + 1];
        }
        postfunct[i] = A[i] * (i + 1);
        if(i != n - 1)
        {
            postfunct[i] += postfunct[i + 1];
        }
    }
    for(int i = 0; i < k; i++)
    {
        vector <pair <int, int> > lines;
        for(int j = i * k; j < min(n, (i + 1) * k); j++)
        {
            lines.push_back({- postsum[j], postfunct[j]});
        }
        if(lines.size() != 0)
        {
        sort(lines.begin(), lines.end());
        vector <pair <int, int> > lines1;
        for(int j  = lines.size() - 1; j >= 0; j--)
        {
            while(lines1.size() > 0 && lines1[lines1.size() - 1].first == lines[j].first)
            {
                lines1.pop_back();
            }
            while(lines1.size() >= 2 && intersection(lines1[lines1.size() - 2], lines1[lines1.size() - 1]) >= intersection(lines1[lines1.size() - 2], lines[j]))
            {
                lines1.pop_back();
            }
            lines1.push_back(lines[j]);
        }
        SQRTCHT[i] =lines1;
        }
    }
    int ans = 0;
    vector <int> lev(k, 0);
    for(int i = 0; i < n; i++)
    {
        int p = i / k;
        p++;
        int l =  p * k;
        int m = postfunct[i] - postsum[i] * (i);
        ans = max(ans, m);
        for(int j = i + 1; j <= min(l, n - 1); j++)
        {
            ans = max(ans, m - postfunct[j] + postsum[j] * i);
        }
        for(int j = p; j < k; j++)
        {
            if(SQRTCHT[j].size() == 0)
            {
                continue;
            }
            while(lev[j] < SQRTCHT[j].size() - 1)
            {
            	if(intersection(SQRTCHT[j][lev[j]], SQRTCHT[j][lev[j] + 1]) > i)
            	{
            		break;
				}
            	lev[j]++;
			}
                ans = max(ans, m - (SQRTCHT[j][lev[j]].second + SQRTCHT[j][lev[j]].first * i));
        }
    }
    cout << ans;
    return 0;
}