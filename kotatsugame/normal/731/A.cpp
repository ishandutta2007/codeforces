#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s;

int make(int a)
{
	if (a <= 0)a += 26;
	if (a > 26)a -= 26;
	if (a > 0 && a <= 26)return a;
	else return make(a);
}

int mint(int now)
{
	if (now >= (int)s.length())return 0;
	int next = s[now]-'a'+1, nowpo;
	if (now == 0)nowpo = 1;
	else nowpo = s[now - 1]-'a'+1;
	int a = abs(next - nowpo);
	int ans = min(a, 26-a);
	ans += mint(now + 1);
	return ans;
}

int main()
{
	cin >> s;
	cout << mint(0) << endl;
    return 0;
}