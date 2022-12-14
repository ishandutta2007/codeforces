#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<pair<long long, long long>> data;

long long a, b, k, h, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n >> h;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i].first >> data[i].second;

    sort(data.begin(), data.end());
    data.push_back({1e15, 1e15+1});

    long long cur_start = data[0].first, cur_high = h, cur_end = cur_start, cur_upper = 0, start_ind = 0;

    while (cur_upper < n)
        {
        cur_end = data[cur_upper].second;
        cur_upper++;
        //cout << cur_start << " " << cur_end << " " << cur_high << endl;

        long long next = data[cur_upper].first-cur_end;


        if (next >= cur_high)
            {

            //cout << "wv " << next << " " << cur_high << endl;
            cur_end+= cur_high;
            cur_high = 0;
            cur_upper;
            break;
            }
        else
            {
            cur_end = data[cur_upper].second;

            //cout << "[cur_high] " << cur_high << "-= [next]" << next << " = ";
            cur_high-= (next);

            //cout << cur_high << endl;
            }

        //cout << cur_start << " " << cur_end << " " << cur_high << endl;
        }
    cur_end+= cur_high;
    cur_high = 0;

    ans = cur_end-cur_start;

    //cout << ans << " " << cur_upper <<  endl;


    while (cur_upper < n)
        {
        start_ind++;
        cur_start+= data[start_ind].first - data[start_ind-1].first;
        cur_high+= data[start_ind].first - data[start_ind-1].second;

        //cout << "new start ind:" << start_ind << " [start] " << cur_start << " [high] " << cur_high <<  " [end] " << cur_end << endl;
        while (cur_upper < n)
            {
            //cur_end = data[cur_upper].second;

            //cout << "[cur_end] " << cur_end << endl;
            long long next = data[cur_upper].first-cur_end;

            if (next >= cur_high)
                {
                cur_end+= cur_high;
                cur_high = 0;
                //cout << "braking at: [next] " << next << " [high] " << cur_high <<  " [end] " << cur_end << " [cur_upper] " << cur_upper <<endl;
                break;
                }
            else
                {
                cur_end = data[cur_upper].second;
                cur_high-= (next);
                }

            //cout << "contine ind:" << start_ind << " [start] " << cur_start << " [high] " << cur_high <<  " [end] " << cur_end << endl;

            cur_upper++;
            }
        cur_end+= cur_high;
        cur_high = 0;



        ans = max(ans, cur_end-cur_start);
        }


    cout << ans;

    return 0;
    }