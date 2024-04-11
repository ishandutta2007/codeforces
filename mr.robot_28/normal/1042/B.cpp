#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int main()
{
	int n, k;
	cin >> n;
	string h;
	map <string, int> Q;
	for(int i = 0; i < n; i++)
	{
		cin >> k >> h;
		 if(h.size() == 2)
		{
			if(h[0] > h[1])
			{
				swap(h[0], h[1]);
			}
		}
		else if(h.size() == 3)
		{
			if(h[0] > h[1])
			{
				swap(h[0], h[1]);
			}
			if(h[1] > h[2])
			{
				swap(h[1], h[2]);
			}
			if(h[0] > h[1])
			{
				swap(h[0], h[1]);
			}
		}
		for(int i = 0; i < h.size(); i++)
		{
			string t ="";
			t +=  h[i];
			if(Q.count(t) == 0)
		{
			Q[t] = k;
		} 
		else
		{
			Q[t] = min(Q[t], k);
		}
		}
		if(Q.count(h) == 0)
		{
			Q[h] = k;
		} 
		else
		{
			Q[h] = min(Q[h], k);
		}
	} 
	map<string, int> :: iterator it;
	vector <bool> used(3, false);
	int min = 300001;
	for(it = Q.begin(); it != Q.end(); it ++)
	{
		h = it -> first;
		if(h.size() == 1)
		{
			if(h[0] == 'A' && Q.count("BC") != 0 && it -> second + Q["BC"] < min)
			{
				min = it -> second + Q["BC"];
			}
			else if(h[0] == 'A' && Q.count("B") != 0 && Q.count("C") != 0 && it -> second + Q["B"] + Q["C"] < min)
			{
				min = it -> second + Q["B"] + Q["C"];
			}
			else if(h[0] == 'B' && Q.count("AC") != 0&& it -> second + Q["AC"] < min)
			{
				min = it -> second + Q["AC"];
			}
			else if(h[0] == 'B' && Q.count("A") != 0 && Q.count("C") != 0 && it -> second + Q["A"] + Q["C"] < min)
			{
				min = it -> second + Q["A"] + Q["C"];
			}
			else if(h[0] == 'C' && Q.count("AB") != 0&& it -> second + Q["AB"] < min)
			{
				min = it -> second + Q["AB"];
			}
			else if(h[0] == 'C' && Q.count("B") != 0 && Q.count("A") != 0 && it -> second + Q["B"] + Q["A"] < min)
			{
				min = it -> second + Q["B"] + Q["A"];
			}
		}
		else if(h.size() == 3 && it -> second < min)
		{
			min = it -> second;
		}
	}
	if(min == 300001)
	{
		cout << -1;
		return 0;
	}
	cout << min;
	return 0;
}