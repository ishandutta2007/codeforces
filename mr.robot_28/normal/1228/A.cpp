 #include<bits/stdc++.h>
 
using namespace std;
main() {
	int l, r;
	cin >> l >> r;
	for(int i = l; i <= r; i++)
	{
		map <int, int>  W;
		int j = i;
		bool flag = true;
		while(j > 0)
		{
			if(W[j % 10] > 0)
			{
				flag = false;
			}
			W[j % 10] ++;
			j = j / 10;
		}
		if(flag)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
   	return 0;
}