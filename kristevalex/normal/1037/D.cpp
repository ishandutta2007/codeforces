#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> numbers;
vector<long long> numbers_simple;





struct num
    {
    long long value;

    num () :
        value (0) {}

    num (long long arg) :
        value (arg) {}

    operator< (num over)
        {
        return numbers[value] < numbers[over.value];
        }

    };

vector<vector<num>> data;

long long a, b, k, n, tmp1, tmp2, ans = 0;




int main()
    {
    FAST;


    cin >> n;

    data.resize(n);
    numbers.resize(n);
    numbers_simple.resize(n);

    for (int i = 0; i < n-1; i++)
        {
        cin >> tmp1 >> tmp2;
        --tmp1;
        --tmp2;
        data[tmp1].push_back(tmp2);
        data[tmp2].push_back(tmp1);
        }

    for (int i = 0; i < n; i++)
        {
        cin >> tmp1;
        numbers[tmp1-1] = i;
        numbers_simple[i] = tmp1-1;
        }

    for (int i = 0; i < n; i++)
        {
        sort(data[i].begin(), data[i].end());
        }

    vector<bool> used (n, false);
    queue<long long> Queue;
    Queue.push(0);
    used[0] = true;

    int i = 0;
    while(!Queue.empty())
        {
        int cur = Queue.front();
        Queue.pop();
        if (numbers_simple[i] != cur)
            {
            cout << "NO";
            //cout << numbers_simple[i] << " " << cur;
            return 0;
            }
        i++;

        for (int j = 0; j < data[cur].size(); j++)
            {
            if (!used[data[cur][j].value])
                {
                //cout << "pusing: " << data[cur][j].value << " from: " << cur << endl;
                Queue.push(data[cur][j].value);
                used[data[cur][j].value] = true;
                }
            }
        }



    cout << "YES";
    return 0;

    }