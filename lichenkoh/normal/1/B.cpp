#include <iostream>
#include <sstream>
#include <assert.h>
using namespace std;
#define ul unsigned long long

bool isalpha(char x)
{
	return (x >= 'A' && x <= 'Z');
}
bool isnum(char x)
{
	return (x >= '0' && x <= '9');
}
//Returns 0 if in Excel format, 1 if in RC format
long long detect(string s, long long len)
{
	long long state = 0;
	for (long long i = 0; i < len; i++) {
		if (state == 0 && isalpha(s[i])) {state = 1;}
		else if (state == 1 && isnum(s[i])) {state = 2;}
		else if (state == 2 && isalpha(s[i])) {state = 3;}
		else if (state == 3 && isnum(s[i])) return 1;
	}
	return 0;
}
long long alpha2num(string s,long long n) {
	//cout <<endl<< "debug"<<s.substr(0,n)<<endl;
	long long sum = 0;
	long long mult = 1;
	for (long long i = n-1; i >= 0; i--) {
		sum += (s[i]-'A'+1) * mult;
		mult *= 26;
	}
	return sum;
}
long long e2r(string s, long long len)
{
	cout << "R";
	long long i = 0;
	for (i = 0; i < len; i++)
	{
		if (!isalpha(s[i])) break;
	}
	cout << s.substr(i);
	cout << "C";
	long long num = alpha2num(s,i);
	cout << num << endl;
	return 0;
}

string n2a(long long n, long long mult) {
	string ans = "";
	if (n <= 0) return "";
	if (1 <= n && n <= 26) {
		if(mult!=1) {
			return "";
		}
		ans += (char)('A'+n-1);
		return ans;
	}
	long long guess = n / mult;
	for (; guess > 0; guess--) {
		ans = n2a(n-guess*mult, mult/26);
		if (ans != "") {
			return (char)('A'+guess-1) + ans;
		}
	}
	return "";
}

string num2alpha(long long n) {
	long long sum = 0;
	long long mult = 1;
	long long digits = 0;
	while (sum < n) {
		mult *= 26;
		sum += mult;
		digits++;
	}
	mult /= 26;
	//cout << "DBG:"<<mult<<endl;
	return n2a(n,mult);
}


long long r2e(string s, long long len)
{
	long long i = 0;
	for (i = 1; i < len; i++)
	{
		if (!isnum(s[i])) break;
	}
	long long numb;
	istringstream(s.substr(i+1)) >> numb;
	cout<<num2alpha(numb);
	istringstream(s.substr(1,i-1)) >> numb;
	cout<<numb<<endl;
}
string toup(string s, long long len)
{
	for (long long i = 0; i < len; i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			s = s[i] - ('a' - 'A');
		}
	}
	return s;
}

int main() {
	ul n = 0;
	cin >> n;
	string s;
	for (long long i = 0; i < n; i++) {
		cin >> s;
		long long len = s.length();
		s = toup(s,len);
		if (detect(s,len) == 0) e2r(s,len);
		else r2e(s,len);
	}
	return 0;
}