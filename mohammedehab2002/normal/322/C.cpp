#include <iostream>
using namespace std;
int arr[100005][2];
int main()
{
	int x,y;
	string s;
	cin >> x >> y >> s;
	for (int i=0;i<s.size();i++)
	{
		arr[i+1][0]=arr[i][0];
		arr[i+1][1]=arr[i][1];
		if (s[i]=='U')
		arr[i+1][1]++;
		else if (s[i]=='D')
		arr[i+1][1]--;
		else if (s[i]=='R')
		arr[i+1][0]++;
		else
		arr[i+1][0]--;
	}
	for (int i=1;i<=s.size();i++)
	{
		int ax=x-arr[i][0],ay=y-arr[i][1];
		if (arr[s.size()][0]==0 || arr[s.size()][1]==0)
		{
			bool bx,by;
			if (arr[s.size()][0]==0)
			bx=(ax==0);
			else
			bx=(ax%arr[s.size()][0]==0 && ax/arr[s.size()][0]>=0);
			if (arr[s.size()][1]==0)
			by=(ay==0);
			else
			by=(ay%arr[s.size()][1]==0 && ay/arr[s.size()][1]>=0);
			if (bx && by)
			{
				cout << "Yes";
				return 0;
			}
		}
		else if (ax%arr[s.size()][0]==0 && ay%arr[s.size()][1]==0 && ax/arr[s.size()][0]==ay/arr[s.size()][1] && ax/arr[s.size()][0]>=0)
		{
			cout << "Yes";
			return 0;
		}
	}
	if (x==0 && y==0)
	cout << "Yes";
	else
	cout << "No";
}