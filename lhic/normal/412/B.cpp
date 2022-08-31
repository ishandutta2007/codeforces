#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N=101000;

const int INF=1000000000;

int arr[2000];
int n,k;

int main()
{
	cin>>n>>k;
	for (int i=0;i<n;++i)
		cin>>arr[i];
	sort(arr,arr+n);
	reverse(arr,arr+n);
	cout<<arr[k-1];
}