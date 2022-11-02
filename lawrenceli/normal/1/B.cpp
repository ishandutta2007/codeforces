#include <iostream>
#include <ios>
#include <cctype>
#include <sstream>

using namespace std;

int n;

bool ok(string s) {
int pr = -1, pc = -1;
for (int i=0; i<s.length(); i++)
if (s[i] == 'C') pc = i;
for (int i=s.length()-1; i>=0; i--)
if (s[i] == 'R') pr = i;
if (pr == -1 || pc == -1) return 0;
return isdigit(s[pc-1]);
}

string toalph(int x) {
string ret = "";
int num = 1, sub = 0;
while (sub <= x) sub += num, num *= 26;
num /= 26;
sub -= num;
num /= 26;
x -= sub;
while (num > 0) {
ret += x / num + 'A';
x %= num;
num /= 26;
}
return ret;
}

int tonum(string x) {
int ret = 0, num = 1;
for (int i=x.length()-1; i >= 0; i--) {
ret += num * (x[i] - 'A' + 1);
num *= 26;
}
return ret;
}

string type1(string s) {
int pr = -1, pc = -1;
for (int i=0; i<s.length(); i++)
if (s[i] == 'C') pc = i;
for (int i=s.length()-1; i>=0; i--)
if (s[i] == 'R') pr = i;
if (pr == -1 || pc == -1) return 0;
stringstream ss;
string x = s.substr(pr+1, pc - pr - 1);
ss << s.substr(pc + 1);
int y; ss >> y;
string ret = "";
ret += toalph(y); ret += x;
return ret;
}

string type2(string s) {
string x = "";
int i;
for (i=0; !isdigit(s[i]); i++) x += s[i];
stringstream ss;
string ret = "R";
ret += s.substr(i);
ret += 'C';
ss << tonum(x);
ret += ss.str();
return ret;
}

int main() {
ios :: sync_with_stdio(false);

cin >> n;
for (int i=0; i<n; i++) {
string s; cin >> s;
if (ok(s)) cout << type1(s) << '\n';
else cout << type2(s) << '\n';
}

return 0;
}