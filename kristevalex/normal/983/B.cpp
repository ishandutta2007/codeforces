#include <bits/stdc++.h>
using namespace std;

//vector<vector<long>> dynamic;

int main()
    {

	long N;
	cin >> N;


	vector<long> data(N);



	vector<vector<long>> dynamic(N, vector<long>(N, 0));

	for (long i = 0; i < N; ++i)
	    {
		cin >> data[i];
	    }

	for (long i = 0; i < N; i++)
	    {
        for (long j = i; j  >= 0; j--)
            {
            if (i == j)
                {
                dynamic[i][j] = data[i];
                }
            else
                {
                dynamic[j][i] = (dynamic[j+1][i])^(dynamic[j][i-1]);
                }
            }
	    }

    for (long i = 1; i < N; i++)
	    {
        for (long j = i-1; j  >= 0; j--)
            {
            dynamic[j][i] = max(dynamic[j+1][i], dynamic[j][i]);
            dynamic[j][i] = max(dynamic[j][i-1], dynamic[j][i]);
            }
	    }

    /*for (long i = 0; i < N; i++)
	    {
        for (long j = 0; j < N; j++)
            {
            cout << setw(8) << dynamic[i][j];
            }
        cout << endl;
	    */



    long m, tmp1, tmp2;
    cin >> m;
    vector<long> ansers (m);




    for (long num_ans = 0; num_ans < m; num_ans++)
	    {
        cin >> tmp1 >> tmp2;

        ansers[num_ans] = dynamic[--tmp1][--tmp2];
        }

    for (long i = 0; i < m; i++)
	    {
        cout << ansers[i] << endl;
	    }



	return 0;
    }