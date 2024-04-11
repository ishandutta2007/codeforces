#include <iostream>
#include <map>
using namespace std;
typedef long long int ll;
typedef pair <ll, int> pli;
const int MAXN = 100005;

map <ll, int> match[26];
string str;
ll sum[MAXN], val[30];

int main(){
	int i; ll ans = 0LL;
	for(i = 1; i <= 26; ++ i)
		cin >> val[i];
	cin >> str;
	sum[0] = val[str[0] - 'a' + 1];
	for(i = 1; i < str.length(); ++ i)
		sum[i] = sum[i - 1] + val[str[i] - 'a' + 1];
	for(i = str.length() - 2; i >= 0; -- i){
		match[str[i + 1] - 'a'][sum[i]] ++;
		ans += match[str[i] - 'a'][sum[i]];
	}
	cout << ans << endl;
	return 0;
}