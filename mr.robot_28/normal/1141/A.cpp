#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if(m % n != 0)
    {
    	cout << -1;
    	return 0;
	}
    m = m / n;
    int count = 0;
	while(m % 2 == 0 || m % 3 == 0)
    {
    	if(m % 2 == 0)
    	{
    		m = m / 2;
		}
		else
		{
			m = m / 3;
		}
		count++;
	}
	if(m != 1)
	{
		cout << -1;
		return 0;
	}
	cout << count;
    return 0;
}