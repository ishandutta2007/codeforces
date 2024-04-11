#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <climits>
using namespace std;
string calc(string *name, long long *point, long long n)
{
	vector <string> names;
	vector <long long> points;
	// First calculate final points
	for (long long i = 0; i < n; i++)
	{
		vector<string>::iterator it = find(names.begin(), names.end(), name[i]);
		long long offset = it - names.begin();
		if (it == names.end()) {
			names.push_back(name[i]);
			points.push_back(point[i]);
		}
		else {
			*(points.begin() + offset) = point[i] +  *(points.begin() + offset);
		}
	}
	long long maxpoint = LONG_MIN;
	long long maxoffset = 0;
	// Then calculate maximum points
	for (vector<long long>::iterator jt = points.begin(); jt != points.end(); ++jt) {
		if (*(jt) > maxpoint) {
			maxpoint = *(jt);
		}
	}
	// Then find all possible winners
	vector<string> winners;
	for (vector<long long>::iterator jt = points.begin(); jt != points.end(); ++jt) {
		if (*(jt) == maxpoint) {
			long long offset = jt - points.begin();
			winners.push_back(*(names.begin() + offset));
		}
	}
	names.clear();
	points.clear();
	long currentpoint = 0;
	// Now find the first winner
	for (long long i = 0; i < n; i++)
	{
		if (find(winners.begin(), winners.end(),name[i]) != winners.end()) {
			vector<string>::iterator it = find(names.begin(), names.end(), name[i]);
			long long offset = it - names.begin();
			if (it == names.end()) {
				names.push_back(name[i]);
				points.push_back(point[i]);
				currentpoint = point[i];
				if (currentpoint >= maxpoint) {
					return name[i];
				}
			}
			else {
				*(points.begin() + offset) = point[i] +  *(points.begin() + offset);
				currentpoint = *(points.begin() + offset);
				if (currentpoint >= maxpoint) {
					return name[i];
				}
			}
		}
	}

}

int main()
{
	long long n;
	cin >> n;
	long long *point = new long long[n];
	string *name = new string[n];
	for (long long i = 0; i < n; i++)
	{
		cin >> name[i];
		cin >> point[i];
	}
	cout << calc(name,point, n) << endl;
}