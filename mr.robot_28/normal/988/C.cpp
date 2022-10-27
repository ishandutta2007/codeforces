#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct book
{
	int sum, ind, ind1;
};
bool cmp(book a, book b)
{
	return a.sum < b.sum;
}
int main()
{
	int k;
	cin >> k;
	vector <vector <int> > A(k);
	vector <int> sum(k);
	for(int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		int p = 0;
		for(int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			A[i].push_back(a);
			p += a;
		}
		sum[i] = p;
	}
	vector < book> B;
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < A[i].size(); j++)
		{
			book l;
			l.sum = sum[i] - A[i][j];
			l.ind = i;
			l.ind1 = j;
			B.push_back(l);
		}
	}
	sort(B.begin(), B.end(), cmp);
	for(int i = 0; i < B.size() - 1; i++)
	{
		if(B[i].sum == B[i + 1].sum && B[i].ind != B[i + 1].ind)
		{
			cout << "YES" << endl;
			cout << B[i].ind + 1 << " " << B[i].ind1 + 1;
			cout << endl << B[i + 1].ind + 1 << " " << B[i + 1].ind1 + 1;
			return 0;
		}
	}
	cout << "NO";
    return 0;
}