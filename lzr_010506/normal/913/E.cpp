#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, T;
int main()
{
	string a;
	int T = read();
	while(T --)
	{
		cin >> a;
		int x = 0;
		int pw = 1;
		rrep(i, 7, 0) x += pw * (a[i] - '0'), pw <<= 1;
		string ans;
		if(x == 0) ans ="!x&x";
		if(x == 1) ans ="x&y&z";
		if(x == 2) ans ="!z&x&y";
		if(x == 3) ans ="x&y";
		if(x == 4) ans ="!y&x&z";
		if(x == 5) ans ="x&z";
		if(x == 6) ans ="!y&x&z|!z&x&y";
		if(x == 7) ans ="(y|z)&x";
		if(x == 8) ans ="!y&!z&x";
		if(x == 9) ans ="!y&!z&x|x&y&z";
		if(x == 10) ans = "!z&x";
		if(x == 11) ans = "!z&x|x&y";
		if(x == 12) ans = "!y&x";
		if(x == 13) ans = "!y&x|x&z";
		if(x == 14) ans = "!(y&z)&x";
		if(x == 15) ans = "x";
		if(x == 16) ans = "!x&y&z";
		if(x == 17) ans = "y&z";
		if(x == 18) ans = "!x&y&z|!z&x&y";
		if(x == 19) ans = "(x|z)&y";
		if(x == 20) ans = "!x&y&z|!y&x&z";
		if(x == 21) ans = "(x|y)&z";
		if(x == 22) ans = "!x&y&z|!y&x&z|!z&x&y";
		if(x == 23) ans = "(x|y)&z|x&y";
		if(x == 24) ans = "!x&y&z|!y&!z&x";
		if(x == 25) ans = "!y&!z&x|y&z";
		if(x == 26) ans = "!x&y&z|!z&x";
		if(x == 27) ans = "!z&x|y&z";
		if(x == 28) ans = "!x&y&z|!y&x";
		if(x == 29) ans = "!y&x|y&z";
		if(x == 30) ans = "!(y&z)&x|!x&y&z";
		if(x == 31) ans = "x|y&z";
		if(x == 32) ans = "!x&!z&y";
		if(x == 33) ans = "!x&!z&y|x&y&z";
		if(x == 34) ans = "!z&y";
		if(x == 35) ans = "!z&y|x&y";
		if(x == 36) ans = "!x&!z&y|!y&x&z";
		if(x == 37) ans = "!x&!z&y|x&z";
		if(x == 38) ans = "!y&x&z|!z&y";
		if(x == 39) ans = "!z&y|x&z";
		if(x == 40) ans = "!(!x&!y|x&y|z)";
		if(x == 41) ans = "!(!x&!y|x&y|z)|x&y&z";
		if(x == 42) ans = "!z&(x|y)";
		if(x == 43) ans = "!z&(x|y)|x&y";
		if(x == 44) ans = "!x&!z&y|!y&x";
		if(x == 45) ans = "!x&!z&y|!y&x|x&z";
		if(x == 46) ans = "!y&x|!z&y";
		if(x == 47) ans = "!z&y|x";
		if(x == 48) ans = "!x&y";
		if(x == 49) ans = "!x&y|y&z";
		if(x == 50) ans = "!(x&z)&y";
		if(x == 51) ans = "y";
		if(x == 52) ans = "!x&y|!y&x&z";
		if(x == 53) ans = "!x&y|x&z";
		if(x == 54) ans = "!(x&z)&y|!y&x&z";
		if(x == 55) ans = "x&z|y";
		if(x == 56) ans = "!x&y|!y&!z&x";
		if(x == 57) ans = "!x&y|!y&!z&x|y&z";
		if(x == 58) ans = "!x&y|!z&x";
		if(x == 59) ans = "!z&x|y";
		if(x == 60) ans = "!x&y|!y&x";
		if(x == 61) ans = "!x&y|!y&x|x&z";
		if(x == 62) ans = "!(x&z)&y|!y&x";
		if(x == 63) ans = "x|y";
		if(x == 64) ans = "!x&!y&z";
		if(x == 65) ans = "!x&!y&z|x&y&z";
		if(x == 66) ans = "!x&!y&z|!z&x&y";
		if(x == 67) ans = "!x&!y&z|x&y";
		if(x == 68) ans = "!y&z";
		if(x == 69) ans = "!y&z|x&z";
		if(x == 70) ans = "!y&z|!z&x&y";
		if(x == 71) ans = "!y&z|x&y";
		if(x == 72) ans = "!(!x&!z|x&z|y)";
		if(x == 73) ans = "!(!x&!z|x&z|y)|x&y&z";
		if(x == 74) ans = "!x&!y&z|!z&x";
		if(x == 75) ans = "!x&!y&z|!z&x|x&y";
		if(x == 76) ans = "!y&(x|z)";
		if(x == 77) ans = "!y&(x|z)|x&z";
		if(x == 78) ans = "!y&z|!z&x";
		if(x == 79) ans = "!y&z|x";
		if(x == 80) ans = "!x&z";
		if(x == 81) ans = "!x&z|y&z";
		if(x == 82) ans = "!x&z|!z&x&y";
		if(x == 83) ans = "!x&z|x&y";
		if(x == 84) ans = "!(x&y)&z";
		if(x == 85) ans = "z";
		if(x == 86) ans = "!(x&y)&z|!z&x&y";
		if(x == 87) ans = "x&y|z";
		if(x == 88) ans = "!x&z|!y&!z&x";
		if(x == 89) ans = "!x&z|!y&!z&x|y&z";
		if(x == 90) ans = "!x&z|!z&x";
		if(x == 91) ans = "!x&z|!z&x|x&y";
		if(x == 92) ans = "!x&z|!y&x";
		if(x == 93) ans = "!y&x|z";
		if(x == 94) ans = "!(x&y)&z|!z&x";
		if(x == 95) ans = "x|z";
		if(x == 96) ans = "!(!y&!z|x|y&z)";
		if(x == 97) ans = "!(!y&!z|x|y&z)|x&y&z";
		if(x == 98) ans = "!x&!y&z|!z&y";
		if(x == 99) ans = "!x&!y&z|!z&y|x&y";
		if(x == 100) ans = "!x&!z&y|!y&z";
		if(x == 101) ans = "!x&!z&y|!y&z|x&z";
		if(x == 102) ans = "!y&z|!z&y";
		if(x == 103) ans = "!y&z|!z&y|x&y";
		if(x == 104) ans = "!(!x&!y|x&y|z)|!x&!y&z";
		if(x == 105) ans = "!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
		if(x == 106) ans = "!x&!y&z|!z&(x|y)";
		if(x == 107) ans = "!x&!y&z|!z&(x|y)|x&y";
		if(x == 108) ans = "!x&!z&y|!y&(x|z)";
		if(x == 109) ans = "!x&!z&y|!y&(x|z)|x&z";
		if(x == 110) ans = "!y&(x|z)|!z&y";
		if(x == 111) ans = "!y&z|!z&y|x";
		if(x == 112) ans = "!x&(y|z)";
		if(x == 113) ans = "!x&(y|z)|y&z";
		if(x == 114) ans = "!x&z|!z&y";
		if(x == 115) ans = "!x&z|y";
		if(x == 116) ans = "!x&y|!y&z";
		if(x == 117) ans = "!x&y|z";
		if(x == 118) ans = "!(x&y)&z|!z&y";
		if(x == 119) ans = "y|z";
		if(x == 120) ans = "!x&(y|z)|!y&!z&x";
		if(x == 121) ans = "!x&(y|z)|!y&!z&x|y&z";
		if(x == 122) ans = "!x&(y|z)|!z&x";
		if(x == 123) ans = "!x&z|!z&x|y";
		if(x == 124) ans = "!x&(y|z)|!y&x";
		if(x == 125) ans = "!x&y|!y&x|z";
		if(x == 126) ans = "!x&y|!y&z|!z&x";
		if(x == 127) ans = "x|y|z";
		if(x == 128) ans = "!(x|y|z)";
		if(x == 129) ans = "!(x|y|z)|x&y&z";
		if(x == 130) ans = "!(!x&y|!y&x|z)";
		if(x == 131) ans = "!(x|y|z)|x&y";
		if(x == 132) ans = "!(!x&z|!z&x|y)";
		if(x == 133) ans = "!(x|y|z)|x&z";
		if(x == 134) ans = "!(!x&y|!y&x|z)|!y&x&z";
		if(x == 135) ans = "!(x|y|z)|(y|z)&x";
		if(x == 136) ans = "!y&!z";
		if(x == 137) ans = "!y&!z|x&y&z";
		if(x == 138) ans = "!(!x&y|z)";
		if(x == 139) ans = "!y&!z|x&y";
		if(x == 140) ans = "!(!x&z|y)";
		if(x == 141) ans = "!y&!z|x&z";
		if(x == 142) ans = "!(!x&y|z)|!y&x";
		if(x == 143) ans = "!y&!z|x";
		if(x == 144) ans = "!(!y&z|!z&y|x)";
		if(x == 145) ans = "!(x|y|z)|y&z";
		if(x == 146) ans = "!(!x&y|!y&x|z)|!x&y&z";
		if(x == 147) ans = "!(x|y|z)|(x|z)&y";
		if(x == 148) ans = "!(!x&z|!z&x|y)|!x&y&z";
		if(x == 149) ans = "!(x|y|z)|(x|y)&z";
		if(x == 150) ans = "!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
		if(x == 151) ans = "!(x|y|z)|(x|y)&z|x&y";
		if(x == 152) ans = "!x&y&z|!y&!z";
		if(x == 153) ans = "!y&!z|y&z";
		if(x == 154) ans = "!(!x&y|z)|!x&y&z";
		if(x == 155) ans = "!(!x&y|z)|y&z";
		if(x == 156) ans = "!(!x&z|y)|!x&y&z";
		if(x == 157) ans = "!(!x&z|y)|y&z";
		if(x == 158) ans = "!(!x&y|z)|!x&y&z|!y&x";
		if(x == 159) ans = "!y&!z|x|y&z";
		if(x == 160) ans = "!x&!z";
		if(x == 161) ans = "!x&!z|x&y&z";
		if(x == 162) ans = "!(!y&x|z)";
		if(x == 163) ans = "!x&!z|x&y";
		if(x == 164) ans = "!x&!z|!y&x&z";
		if(x == 165) ans = "!x&!z|x&z";
		if(x == 166) ans = "!(!y&x|z)|!y&x&z";
		if(x == 167) ans = "!(!y&x|z)|x&z";
		if(x == 168) ans = "!(x&y|z)";
		if(x == 169) ans = "!(x&y|z)|x&y&z";
		if(x == 170) ans = "!z";
		if(x == 171) ans = "!z|x&y";
		if(x == 172) ans = "!x&!z|!y&x";
		if(x == 173) ans = "!(x&y|z)|x&z";
		if(x == 174) ans = "!y&x|!z";
		if(x == 175) ans = "!z|x";
		if(x == 176) ans = "!(!y&z|x)";
		if(x == 177) ans = "!x&!z|y&z";
		if(x == 178) ans = "!(!y&x|z)|!x&y";
		if(x == 179) ans = "!x&!z|y";
		if(x == 180) ans = "!(!y&z|x)|!y&x&z";
		if(x == 181) ans = "!(!y&z|x)|x&z";
		if(x == 182) ans = "!(!y&x|z)|!x&y|!y&x&z";
		if(x == 183) ans = "!x&!z|x&z|y";
		if(x == 184) ans = "!x&y|!y&!z";
		if(x == 185) ans = "!(x&y|z)|y&z";
		if(x == 186) ans = "!x&y|!z";
		if(x == 187) ans = "!z|y";
		if(x == 188) ans = "!(!x&!y&z|x&y)";
		if(x == 189) ans = "!x&!z|!y&x|y&z";
		if(x == 190) ans = "!x&y|!y&x|!z";
		if(x == 191) ans = "!z|x|y";
		if(x == 192) ans = "!x&!y";
		if(x == 193) ans = "!x&!y|x&y&z";
		if(x == 194) ans = "!x&!y|!z&x&y";
		if(x == 195) ans = "!x&!y|x&y";
		if(x == 196) ans = "!(!z&x|y)";
		if(x == 197) ans = "!x&!y|x&z";
		if(x == 198) ans = "!(!z&x|y)|!z&x&y";
		if(x == 199) ans = "!(!z&x|y)|x&y";
		if(x == 200) ans = "!(x&z|y)";
		if(x == 201) ans = "!(x&z|y)|x&y&z";
		if(x == 202) ans = "!x&!y|!z&x";
		if(x == 203) ans = "!(x&z|y)|x&y";
		if(x == 204) ans = "!y";
		if(x == 205) ans = "!y|x&z";
		if(x == 206) ans = "!y|!z&x";
		if(x == 207) ans = "!y|x";
		if(x == 208) ans = "!(!z&y|x)";
		if(x == 209) ans = "!x&!y|y&z";
		if(x == 210) ans = "!(!z&y|x)|!z&x&y";
		if(x == 211) ans = "!(!z&y|x)|x&y";
		if(x == 212) ans = "!(!z&x|y)|!x&z";
		if(x == 213) ans = "!x&!y|z";
		if(x == 214) ans = "!(!z&x|y)|!x&z|!z&x&y";
		if(x == 215) ans = "!x&!y|x&y|z";
		if(x == 216) ans = "!x&z|!y&!z";
		if(x == 217) ans = "!(x&z|y)|y&z";
		if(x == 218) ans = "!(!x&!z&y|x&z)";
		if(x == 219) ans = "!x&!y|!z&x|y&z";
		if(x == 220) ans = "!x&z|!y";
		if(x == 221) ans = "!y|z";
		if(x == 222) ans = "!x&z|!y|!z&x";
		if(x == 223) ans = "!y|x|z";
		if(x == 224) ans = "!(x|y&z)";
		if(x == 225) ans = "!(x|y&z)|x&y&z";
		if(x == 226) ans = "!x&!y|!z&y";
		if(x == 227) ans = "!(x|y&z)|x&y";
		if(x == 228) ans = "!x&!z|!y&z";
		if(x == 229) ans = "!(x|y&z)|x&z";
		if(x == 230) ans = "!(!y&!z&x|y&z)";
		if(x == 231) ans = "!x&!y|!z&y|x&z";
		if(x == 232) ans = "!((x|y)&z|x&y)";
		if(x == 233) ans = "!((x|y)&z|x&y)|x&y&z";
		if(x == 234) ans = "!x&!y|!z";
		if(x == 235) ans = "!x&!y|!z|x&y";
		if(x == 236) ans = "!x&!z|!y";
		if(x == 237) ans = "!x&!z|!y|x&z";
		if(x == 238) ans = "!y|!z";
		if(x == 239) ans = "!y|!z|x";
		if(x == 240) ans = "!x";
		if(x == 241) ans = "!x|y&z";
		if(x == 242) ans = "!x|!z&y";
		if(x == 243) ans = "!x|y";
		if(x == 244) ans = "!x|!y&z";
		if(x == 245) ans = "!x|z";
		if(x == 246) ans = "!x|!y&z|!z&y";
		if(x == 247) ans = "!x|y|z";
		if(x == 248) ans = "!x|!y&!z";
		if(x == 249) ans = "!x|!y&!z|y&z";
		if(x == 250) ans = "!x|!z";
		if(x == 251) ans = "!x|!z|y";
		if(x == 252) ans = "!x|!y";
		if(x == 253) ans = "!x|!y|z";
		if(x == 254) ans = "!(x&y&z)";
		if(x == 255) ans = "!x|x";
		cout << ans << endl;
	}

	return 0;
}