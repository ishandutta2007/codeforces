#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    long long arr[n],ans=1000000000000000;
    for (int i=0;i<n;i++)
    cin >> arr[i];
    for (int i=0;i<n-1;i++)
    {
    	if (s[i]=='R' && s[i+1]=='L')
    	ans=min(ans,arr[i+1]-arr[i]);
	}
	if (ans==1000000000000000)
	cout << -1;
	else
	cout << ans/2;
}