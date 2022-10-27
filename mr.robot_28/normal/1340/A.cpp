#include<bits/stdc++.h>
using namespace std;

signed main() {	
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	cout.tie(NULL);
  	int t;
  	cin >> t;
  	while(t--)
  	{
  		int n;
  		cin >> n;
  		vector <int> A(n);
  		vector <int> pos(n);
  		for(int i = 0; i < n; i++)
  		{
  			cin >> A[i];
  			A[i]--;
  			pos[A[i]] = i;
		}
		vector <bool> used(n, false);
		bool flag = true;
		int i = 0;
		while(i < n)
		{
			int k = pos[i];
			while(k + 1 < n && !used[k + 1])
			{
				if(A[k + 1] != A[k] + 1)
				{
					flag = false;
					break;
				}
				used[k] = true;
				k++;
			}
			used[k] = true;
			if(!flag)
			{
				break;
			}
			i += k - pos[i] + 1;
		}
		if(flag)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
    return 0;
}