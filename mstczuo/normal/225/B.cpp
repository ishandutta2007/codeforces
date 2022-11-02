# include <iostream>
# include <cstdio>
# include <vector>
using namespace std;

vector<long long> ans;
long long s,f[100],sum[100];
int k;

int main()
{
	cin >> s >> k; int i;
	f[0] = f[1] = 1;
	sum[0] = 1; sum[1] = 2;
	
	for(i=2; f[i-1]<s && i<=k; i++)
		f[i] = sum[i-1], sum[i] = sum[i-1] + f[i];
	for( ; f[i-1]<s; i++) {
		f[i] = sum[i-1] - sum[i-1-k];
		sum[i] = sum[i-1] + f[i];
	}
	
	for( --i; s>0; ) {
		while(f[i]>s) i--;
		ans.push_back(f[i]);
		s -= f[i]; i--;
	}
	
	if(ans.size()==1) ans.push_back(0);
	
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++)
		cout << ans[i] <<' ';
	cout << endl;
	
//	while(1);
}