#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	#define int long long
    int n, k;
    cin >> n >> k;
    int sum = k * (k + 1) / 2;
    if(sum > n)
    {
    	cout << "NO";
    	return 0;
	}
	vector <int> A(k + 1);
	for(int i = 0; i< k; i++)
	{
		A[i + 1] = i + 1;
	}
	sum = n - sum;
	A[0] = 1e9;
	int cnt = 0, x, y;
	for(int i = 1; i <= k; i++)
	{
		A[i] += cnt;
		x = 2 * A[i - 1] - A[i];
		y = min(x, sum / (k - i + 1));
		cnt += y;
		A[i] += y;
		sum -= y * (k - i + 1);
 	}
 	if(sum != 0)
 	{
 		cout << "NO";
 		return 0;
	 }
	cout << "YES" << endl;
	for(int i = 1; i <= k; i++)
	{
		cout << A[i] << " ";
	}
    return 0;
}