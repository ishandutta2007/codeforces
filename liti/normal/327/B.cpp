#include<iostream>
using namespace std;
int mark[5000000];
void gharbal()
{
	for(int i = 2; i <= 5000000; i++)
		if( !mark[i] ) 
			for(int j = i + i; j <= 5000000; j += i)
				mark[j]++;
}
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	gharbal();
	for(int i = 2; i < 5000000; i++)
	{
		//cout << i << " " << mark[i] << endl;
		if(mark[i] == 0)
		{
			cout << i << " ";
			cnt++;
		}
		if(cnt == n)
			return 0;
	}
	return 0;
}