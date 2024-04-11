#include <bits/stdc++.h>
using namespace std;
int SIZE, current_lenght, max_length, max_value;
map<int, int> MAP;

int main()
    {
	cin >> SIZE;

	vector<int> data (SIZE+1);


	for(int i = 1; i <= SIZE; i++)
	    {
		cin >> data[i];
		MAP[data[i]] = MAP[data[i]-1] + 1;
		current_lenght = MAP[data[i]];
		if(current_lenght > max_length) max_length = current_lenght, max_value = data[i];
	    }

	cout << max_length << endl;
	current_lenght = max_value - max_length + 1;

	for(int i = 1; i <= SIZE; i++)
	    {
		if(data[i] == current_lenght)
            {
            cout << i << " ";
            current_lenght++;
            }
	    }

	return 0;
    }