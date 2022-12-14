#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long a, b, k, n, m, tmp, ans = 0;


vector<pair<int, int>> data(n);

//#define ld long double


long double dist_2 (long double x1, long double y1, long double x2, long double y2)
    {
    return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }


long double getans(long double coord)
    {
    //cout << coord << endl;
    long double max_ans = 0;
    for (int i = 0; i < n; i++)
        {
        long double cur_ans = dist_2(coord, 0, data[i].first, data[i].second);

        //cout << cur_ans << " ";

        cur_ans/= (2*fabs(data[i].second));

        //cout << (2*fabs(data[i].second)) << endl;


        max_ans = max(max_ans, cur_ans);
        }

    //cout << max_ans << endl;
    return max_ans;
    }


int main()
    {
    //FAST;


    int x_max = -(int)1e9, x_min = (int)1e9;
    int y_max = -(int)1e9, y_min = (int)1e9;


    cin >> n;


    data.resize(n);

    for (int i = 0; i < n; i++)
        {
        cin >> data[i].first >> data[i].second;
        x_min = min(x_min, data[i].first);
        x_max = max(x_max, data[i].first);
        y_min = min(y_min, data[i].second);
        y_max = max(y_max, data[i].second);
        }

    //cout << y_min << " " << y_max << endl;

    if (y_min < 0 && y_max > 0)
        {
        cout << -1;
        return 0;
        }

    long double anser = 1000000000000000000;


    long double low = x_min;
    long double high = x_max;

    //printf("%lf", anser);




    long long counter = 0;
    while (counter < 300)
        {
        counter++;
        //cout << "hello";

        long double middle1 = (2*low + high)/3;
        long double middle2 = (low + 2*high)/3;

        long double ans2 = getans(middle1);
        //printf("%lf\n", ans2);

        long double ans3 = getans(middle2);

        anser = min(anser, min(ans2, ans3));

        if (ans2 < ans3)
            high = middle2;
        else
            low = middle1;
        }

    long long a = anser;
    cout << a << ".";
    anser-= a;
    anser*= 100000000000;
    a = anser;
    cout << a;
    //printf("%.13lf", anser);

    return 0;
    }