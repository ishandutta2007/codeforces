#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


char s[100500];


int main()
{ 
	vector<pair<int, int> > vec;
	int a;
	scanf("%d%s", &a, s);
	int n = strlen(s);
	int sgn = 1;
	for(int i = 0; i < n; i++)
	{
		int v = 1, bit;
		if(isdigit(s[i]))
		{
			sscanf(s + i, "%d", &v);
			while(isdigit(s[i]) )
			{
				i++;
			}
			i++;
		}
		if(s[i] == '+')
		{
			bit = 'L';
		}
		else
		{
			bit = 'R';
		}
		i += 3;
		vec.push_back(make_pair(v * sgn, bit) );
		if(s[i] == '-')
		{
			sgn = -1;
		}
		else
		{
			sgn = 1;
		}
	}
	sort(vec.begin(), vec.end());
	int res = 0;
	for(int i = 0; i < vec.size(); i++)
	{
		if(vec[i].second == 'L')
		{
			a++;
			res += vec[i].first * a;
		}
		else
		{
			res += vec[i].first * a;
			a++;
		}
	}
	printf("%d\n", res);
	return 0;
}