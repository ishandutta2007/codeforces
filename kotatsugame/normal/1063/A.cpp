#include<iostream>
#include<algorithm>
using namespace std;
int cnt[26];
string S;
int N;
main()
{
	cin>>N>>S;
	string ans=S;
	sort(ans.begin(),ans.end());
	cout<<ans<<endl;
}