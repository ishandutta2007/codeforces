#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define sp ' '
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
const double pi=acos(-1);
map<string,string> ten;
map<string,string> phu;
signed main()
{
int n,m;
cin>>n>>m;
string s1,s2;
while(n--){
	cin>>s1>>s2;
	ten[s2+';']=s1;
}
string s3,s4;
while(m--){
	cin>>s3>>s4;
	cout<<s3<<' '<<s4<<' '<<'#'<<ten[s4]<<endl;
	}
}