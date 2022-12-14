#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<string> ansers;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> m;

    ansers.resize(m);

    for (int ans_i = 0; ans_i < m; ans_i++)
        {
        string text;

        cin >> text;

        int data[3] = {};

        for (int i = 0; i < text.size(); i++)
            {
            if (text[i] <= 'z' && text[i] >= 'a') data[0]++;
            else if (text[i] <= 'Z' && text[i] >= 'A') data[1]++;
            else data[2]++;
            }


        if (data[0] >= 1 && data[1] >= 1 && data[2] >= 1)
            {
            ansers[ans_i] = text;
            continue;
            }

        int q_good = 0;

        for (int i = 0; i < 3; i++)
            {
            if (data[i]) q_good++;
            }

        if (q_good == 1)
            {
            if (data[0] >= 1)
                {
                text[1] = '1';
                text[2] = 'A';
                }

            if (data[1] >= 1)
                {
                text[1] = 'a';
                text[2] = '1';
                }

            if (data[2] >= 1)
                {
                text[1] = 'A';
                text[2] = 'a';
                }

            ansers[ans_i] = text;
            continue;
            }
        else
            {
            int nead = 0;
            if (data[1] == 0) nead = 1;
            if (data[2] == 0) nead = 2;

            //cout << nead << endl;

            for (int i = 0; i < text.size(); i++)
                {
                int cur = 0;
                if (text[i] <= 'z' && text[i] >= 'a') cur = 0;
                else if (text[i] <= 'Z' && text[i] >= 'A') cur = 1;
                else cur = 2;

                //cout << cur << " :cur" << endl;

                if (data[cur] >= 2)
                    {
                    //cout << i << " :i" << endl;

                    if (nead == 0) text[i] = 'a';
                    if (nead == 1) text[i] = 'A';
                    if (nead == 2) text[i] = '1';

                    ansers[ans_i] = text;
                    break;
                    }
                }
            }

        }




    for (int i = 0; i < m; i++)
        {
        cout << ansers[i] << endl;
        }

    return 0;
    }