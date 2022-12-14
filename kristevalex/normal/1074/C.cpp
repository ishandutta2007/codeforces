#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<pair<int, int>> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i].first >> data[i].second;

    int minx = 1e9+1, minx_ind1 = 0, minx_ind2 = 0;
    int miny = 1e9+1, miny_ind1 = 0, miny_ind2 = 0;
    int maxx = -1e9-1, maxx_ind1 = 0, maxx_ind2 = 0;
    int maxy = -1e9-1, maxy_ind1 = 0, maxy_ind2 = 0;

    for (int i = 0; i < n; i++)
        {
        if (data[i].first < minx)
            {
            minx = data[i].first;
            minx_ind1 = i;
            }
        else if (data[i].first == minx)
            minx_ind2 = i;

        if (data[i].second < miny)
            {
            miny = data[i].second;
            miny_ind1 = i;
            }
        else if (data[i].second == miny)
            miny_ind2 = i;


        if (data[i].first > maxx)
            {
            maxx = data[i].first;
            maxx_ind1 = i;
            }
        else if (data[i].first == maxx)
            maxx_ind2 = i;

        if (data[i].second > maxy)
            {
            maxy = data[i].second;
            maxy_ind1 = i;
            }
        else if (data[i].second == maxy)
            maxy_ind2 = i;


        }

    long long ans3 = 0, ans4 = maxx-minx+maxy-miny;

    //cout << maxx << " " << minx << " " << maxy << " " << miny << endl;


    int nums[8] = {minx_ind1, minx_ind2, miny_ind1, miny_ind2, maxx_ind1, maxx_ind2, maxy_ind1, maxy_ind2};

    for (int k = 0; k < 8; ++k)
        {
        for (int j = 0; j < 8; ++j)
            {
            if (j == k) continue;
            for (int i = 0; i < n; ++i)
                {
                int minx_ = data[i].first;
                int miny_ = data[i].second;
                int maxx_ = data[i].first;
                int maxy_ = data[i].second;

                //if (ans3 != 7) cout << endl << maxx_ << " " << minx_ << " " << maxy_ << " " << miny_ << endl;

                minx_ = min(minx_, data[nums[j]].first);
                miny_ = min(miny_, data[nums[j]].second);
                maxx_ = max(maxx_, data[nums[j]].first);
                maxy_ = max(maxy_, data[nums[j]].second);

                //if (ans3 != 7) cout << maxx_ << " " << minx_ << " " << maxy_ << " " << miny_ << "  " << data[nums[j]].first << " " << data[nums[j]].second << endl;

                minx_ = min(minx_, data[nums[k]].first);
                miny_ = min(miny_, data[nums[k]].second);
                maxx_ = max(maxx_, data[nums[k]].first);
                maxy_ = max(maxy_, data[nums[k]].second);

                long long cur = maxx_-minx_+maxy_-miny_;




                if (ans3 < cur) ans3 = cur;


                }
            }
        }

    cout << ans3*2 << " ";
    for (int i = 4; i <= n; i++)
        {
        cout << ans4*2 << " ";
        }

    return 0;
    }