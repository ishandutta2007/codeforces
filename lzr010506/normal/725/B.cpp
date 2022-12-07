#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll Ch, ans;
char ch[1110]; 
int A[6] = {4, 5, 6, 3, 2, 1} ; 
int main()
{
	scanf("%s",ch + 1) ; 
	int L = strlen(ch + 1); 
	for (int i = 1; i < L; i ++) 
		Ch = Ch * 10 + ch[i] - '0';
	if ((Ch - 1) % 4 < 2) ans = Ch - 1; 
	else ans = Ch - 3;
	ans += 1ll * ((Ch - 1) / 4) * 12;  
	if (((Ch - 1) % 4) & 1) ans += 6;
	ans += A[ch[L] - 'a'];
	cout << ans << endl;
	return 0;
}