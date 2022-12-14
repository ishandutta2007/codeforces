#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

struct Per
{
    int start_, end_;

    operator< (Per over)
        {
        return start_ < over.start_;
        }
};


vector<Per> data;




long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n >> m >> k;

    data.resize(n+2);

    data[0].end_ = 0;
    data[n+1].start_ = m;

    for (int i = 1; i <= n; i++)
        {
            cin >> data[i].start_ >> tmp;
            data[i].end_ = data[i].start_ + tmp;

        }

    sort(data.begin(), data.end());


    for (int i = 0; i <= n; i++)
        {
        ans+= (data[i+1].start_ - data[i].end_)/k;
        }

    cout << ans;

    return 0;
    }