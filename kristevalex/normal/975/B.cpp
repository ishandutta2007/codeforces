#include <bits/stdc++.h>
using namespace std;




long long data[14] = {};




int main()
    {

    for (int i = 0; i < 14; i++)
        {
        cin >> data[i];
        }

    long long max_score = 0;

    for (int i = 0; i < 14; i++)
        {
        long long current = 0;
        long long full = (data[i]/14);
        long long anti_ful = data[i]%14;


        vector<long long> adds (14, full);

        for (int j = i+1; j < i+1+anti_ful; j++)
            {
            adds[j%14]++;
            }

        for (int j = 0; j < 14; j++)
            {
            //cout << data[j] << " " << adds[j] << ", ";
            if (j != i)
                if ((data[j]+adds[j])%2 == 0) current+= (data[j]+adds[j]);

            if (j == i)
                if (adds[j]%2 == 0) current+= (adds[j]);
            }
        //
        //cout << endl;
        //cout << current << endl;
        if (max_score < current) max_score = current;
        }



    cout << max_score;



    return 0;
    }