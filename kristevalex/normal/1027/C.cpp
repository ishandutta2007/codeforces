#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

struct PQ
    {
    int p, q;

    PQ () :
        p(1),
        q(0) {}

    operator< (PQ over)
        {
        return p*over.q < q*over.p;
        }
    };

vector<pair<int, int>> data;

int n = 1000000, m = 1000000, tmp;

int main()
    {
    FAST;


    cin >> m;

    data.resize(n);


    for (int i = 0; i < m; i++)
        {
        cin >> n;

        vector<int> lengths (n);

        for (int j = 0; j < n; j++)
            {
            cin >> lengths[j];
            }

        sort(lengths.begin(), lengths.end());

        stack<int> Stack;

        for (int j = 1; j < n; j++)
            {
            if (lengths[j] != lengths[j-1]) continue;

            Stack.push(lengths[j]);
            //cout << "hello" << lengths[j] << endl;
            j++;
            }

        PQ lowest;

        //cout << Stack.size();
        while(Stack.size() > 1)
            {
            int bigger, smaller;

            bigger = Stack.top();
            Stack.pop();
            smaller = Stack.top();

            PQ cur;
            cur.p = bigger;
            cur.q = smaller;

            if (cur < lowest) lowest = cur;
            //cout << "cur: " << cur.p << " " << cur.q << endl;
            }

        data[i].first = lowest.p;
        data[i].second = lowest.q;

        }




    for (int i = 0; i < m; i++)
        {
        cout << data[i].first << " " << data[i].first << " " << data[i].second << " "<< data[i].second << endl;
        }


    return 0;

    }