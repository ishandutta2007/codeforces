#include<iostream>
#include<algorithm>
using namespace std;
string T="Timur";
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	sort(T.begin(),T.end());
	int t;cin>>t;
	for(;t--;)
	{
		int n;cin>>n;
		string s;cin>>s;
		sort(s.begin(),s.end());
		cout<<(T==s?"YES\n":"NO\n");
	}
}