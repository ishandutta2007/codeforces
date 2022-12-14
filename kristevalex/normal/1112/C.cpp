#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(0); \
             cout.tie(0) \

#define pii pair<int, int>
#define ll long long

vector<ll> data;

vector<int> cnt;
vector<int> cnt_;

long long a, b, n, m, k, tmp, ans = 0;

void as (int idx)
    {
    vector<int> ansr;

    for (int i = 0; i < idx%k; ++i)
        {
        ansr.push_back(i);
        }

    int sum = 0;

    for (int i = 0; i < cnt.size(); ++i)
        {
        sum+= cnt[i];
        }

    //cout << "h: " << sum;

    for (int i = idx; sum > 0; ++i)
        {
        //cout << sum << " ";

        if (cnt[data[i]] > 0)
            {
            sum--;
            cnt[data[i]]--;
            }
        else
            {
            ansr.push_back(i);
            }
        }

    cout << min((ll)ansr.size(), n-k*a) << endl;
    for (int i = 0; i < min((ll)ansr.size(), n-k*a); ++i)
        {
        cout << ansr[i]+1 << " ";
        }
    }


int main ()
    {
    FAST;

    cin >> n >> k >> a >> m;

    data.resize(n);
    cnt.resize(500005);
    cnt_.resize(500005);

    for (int i = 0; i < n; ++i)
        {
        cin >> data[i];
        data[i]--;
        }

    int sum_ = 0;
    for (int i = 0; i < m; ++i)
        {
        cin >> tmp;
        --tmp;
        cnt[tmp]++;
        cnt_[tmp]++;
        sum_++;
        }




    int st = 0, nd = 0;

    while(nd <= n)
        {
        if (sum_ > 0)
            {
            if (nd == n) break;
            if (cnt_[data[nd]] > 0)
                {
                sum_--;
                }
            cnt_[data[nd]]--;

            ++nd;
            }

        //cout << " " << st << " " << nd << endl;


        if (sum_ == 0)
            {
            if (st%k + max(0ll, (nd-st) - k) <= n-k*a)
                {
                as(st);

                return 0;
                }

            if (cnt_[data[st]] >= 0)
                {
                sum_++;
                }
            cnt_[data[st]]++;

            ++st;


            if (st%k + max(0ll, (nd-st) - k) <= n-k*a && sum_ == 0)
                {
                as(st);

                //cout << "ans " << st;

                return 0;
                }

            }
        }


    cout << -1;
    return 0;

    //cout << n-k*a;
    }