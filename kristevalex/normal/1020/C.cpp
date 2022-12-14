#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

long long N,M,N_old,  S, C, H, U, dist1 = 0, dist2 = 0;




struct XY
    {
    int x, y;

    XY () :
        x(0),
        y(0) {}

    operator < (XY over)
        {
        return (x < over.x);
        }
    };


struct DP
    {
    int num, val;


    operator< (DP over)
        {
        return val<over.val;
        }

    };





string text;


//vector<long long> data;
vector<DP> cost;





int main()
    {
    //FAST;

    long long anser = LLONG_MAX;
    long long HAVE = 0, Max = 0;

    cin >> N >> M;
    N_old = N;

    vector<vector<DP>> val_part (M);

    //data.resize(N);
    cost.resize(N);

    for (int i = 0; i < N; i++)
        {
        cin >> cost[i].num >> cost[i].val;
        cost[i].num--;
        if (cost[i].num == 0)
            {
            HAVE++;
            i--;
            N--;
            continue;
            }

        DP tmp = cost[i];
        tmp.num = i;

        val_part[cost[i].num].push_back(tmp);
        cost[i] = tmp;
        }
    //cout << "hello";
cost.resize(N);

    for (int i = 1; i < M; i++)
        {
        sort(val_part[i].begin(), val_part[i].end());
        if (val_part[i].size() > Max) Max = val_part[i].size();
        }

    sort(cost.begin(), cost.end());

    //cout << "hello";

    if (HAVE > min(Max, N_old-1))
        {
        cout << 0;
        return 0;
        }

    long long MIN_ANS = LLONG_MAX;

    cout << endl;


    for (int nead = HAVE+1; nead <= min(Max, N_old-1)+1; nead++)
        {
        long long curr_ans = 0;
        long long curr_heave = HAVE;

        vector<bool> mask (N, false);

        //cout << nead << endl;

        for (int i = 1; i < M; i++)
            {
            if (curr_heave > (Max))break;
            if (val_part[i].size() >= nead)
                for (int j = 0; j <= val_part[i].size() - nead; j++)
                    {
                    //cout << i << " ! " << j << endl;
                    curr_ans+= val_part[i][j].val;
                    curr_heave++;
                    mask[val_part[i][j].num] = true;
                    //cout << j << "{" << val_part[i][j].val << ", " << curr_ans << " 0}, " << endl;
                    }

            }



        for (int j = 0; curr_heave < nead; j++)
                {
                if (!mask[cost[j].num])
                    {
                    curr_heave++;
                    curr_ans+= cost[j].val;
                    //cout << j << "{" << cost[j].val << ", " << curr_ans << " 1}, " << endl;
                    }
                }

        if (curr_ans < anser) anser = curr_ans;

        //cout <<endl;
        for (int i = 0; i < N; i++)
            {
            //cout << mask[i];
            }


        //cout << endl << "curr_ans " << curr_ans << " for " << nead << endl << endl;
        }

    cout << anser;

    }