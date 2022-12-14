#include <bits/stdc++.h>
using namespace std;

//vector<vector<long>> dynamic;

int main()
    {


	long N, k;
	cin >> N >> k;


	vector<long> data(N);
    vector<long> data_sleep(N);



	vector<long> dynamic(N-k+1);

	for (long i = 0; i < N; ++i)
	    {
		cin >> data[i];
	    }

	for (long i = 0; i < N; ++i)
	    {
		cin >> data_sleep[i];
	    }


    dynamic[0] = 0;
	for (int i = 0; i < N; i++)
	    {
	    if (i < k) dynamic[0]+= data[i];
	    else dynamic[0]+= data[i]*data_sleep[i];
	    }

    //cout << "minute 0 :" << dynamic[0] << endl;

    long ans = dynamic[0];
	for (long i = 1; i < N-k+1; i++)
	    {
        dynamic[i] = dynamic[i-1] + (1-data_sleep[i+k-1])*data[i+k-1] - (1-data_sleep[i-1])*data[i-1];
        if (ans < dynamic[i]) ans = dynamic[i];
        //cout << "minute " << i << " :" << dynamic[i] << endl;

	    }



    cout << ans << endl;




	return 0;
    }