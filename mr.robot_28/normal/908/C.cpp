#include<bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, r;
	cin >> n >> r;
	vector <int> x(n);
	vector <double> ans(n);
	for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        if(i == 0)
        {
            ans[i] = r;
        }
        else
        {
            double maxy = r;
            for(int j = 0; j < i; j++)
            {
                if(abs(x[i] - x[j]) <= 2 * r)
                {
                    double dx = x[i] - x[j];
                    maxy = max(maxy, ans[j] + sqrt(4 * r * r - dx * dx));
                }
            }
            ans[i] = maxy;
        }
        cout << fixed << setprecision(10) << ans[i] << " ";
    }
	return 0;
}