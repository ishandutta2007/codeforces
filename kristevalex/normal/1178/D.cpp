#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

void mn_ans()
    {
    int p = n;

    for (int i = p; i <= 2*p; i++)
        {
        if (i == 2*p)
            {
            cout << "uexpexted eerrror no prime" << endl;
            return;
            }

        bool prime = true;
        int SQRT = sqrt(i);

       // cout << SQRT << endl;
        for (int j = 2; j <= SQRT; j++)
            {
            if (i%j == 0)
                {
                prime = false;
                break;
                }
            }


        if (prime)
            {
            p = i;
            break;
            }
        }


    ///cout <<endl<<"prime:" <<p << ": prime "<<  endl;



    int to_add = p - n;


    vector<pair<int, int>> graph;


    int min_free = 0;
    while (to_add >= 9)
        {
        for (int i = 0; i < 6; i++)
            {
            for (int j = i+1; j < 6; j++)
                {
                graph.push_back({min_free+i, min_free+j});
                }
            }
        to_add-= 9;


        min_free+= 6;

        if (min_free >= n)
            {
            cout << "unexpected eerror to few sparce#in" << endl;
            return;
            }
        }

    graph.push_back({min_free, n-1});

    if (min_free+1 >= n-1)
        {
        cout << "unexpected eerror to few sparce" << endl;
        return;
        }


    for (int i = min_free; i <= n-2; i++)
        {
        graph.push_back({i, i+1});
        }


    if (to_add == 1)
        {
        if (min_free+2 < n-1)
            graph.push_back({min_free, min_free+2});
        else
            {
            cout << "unexpected eerror to few sparce#out" << endl;
            return;
            }

        }
    else
        for (int i = min_free; i < min_free + to_add; i++)
            {
            if (i+to_add >= n)
                {
                cout << "unexpected eerror to few vertex" << endl;
                return;
                }
            graph.push_back({i, i+to_add});
            }


    cout << graph.size() << endl;
    for (int i = 0; i < graph.size(); i++)
        {
        cout << graph[i].first+1 << " " << graph[i].second+1 << endl;
        }
    }





int main()
    {
    FAST;


    cin >> n;

    if (n > 1)
        {
        mn_ans();

        return 0;
        }








    return 0;
    }