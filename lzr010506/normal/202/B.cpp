#include <bits/stdc++.h>
const int N=110;
const int inf=0x3f3f3f3f;

using namespace std;

int n,c[N],m,f[N];
string a[N];
string b[N][N];

int main()
{
	cin>>n;
	for(int i = 0; i < n; i ++) cin>>a[i];
	cin>>m;
	for(int i = 0; i < m; i ++)
	{
		cin>>c[i];
		for(int j = 0; j < c[i]; j ++)
			cin>>b[i][j];
	}
	for(int i = 0; i < n; i ++) f[i]=i;
	int ret=inf,id=inf;
	do
	{
		int cnt = 0;
		for(int i = 0; i < n; i ++)
			for(int j = i + 1; j < n; j ++)
				cnt += (f[i] > f[j]);
		for(int k = 0; k < m; k ++)
			for(int i = 0, j = 0; i < c[k];)
			{
				if(b[k][i] == a[f[j]]) j++;
				i ++;
				if(j == n)
				{
					if(cnt < ret) ret = cnt, id = k;
					else if(cnt == ret && id > k) id = k;
					break;
				}
			}
	}while(next_permutation(f, f + n));
	if(ret == inf) cout<<"Brand new problem!"<<endl;
	else
	{
		cout << id + 1 << endl;
		cout << "[:";
		for(int i = 0; i < n * (n - 1) / 2 - ret + 1; i ++)
			cout << "|";
		cout << ":]" << endl;
	}
	return 0;
}